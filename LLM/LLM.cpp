#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#ifdef _WIN32
// 直接声明所需 Win32 API，避免包含 <windows.h> 触发 clangd 对 intrin.h 的误报
extern "C" __declspec(dllimport) int __stdcall SetConsoleOutputCP(unsigned int);
extern "C" __declspec(dllimport) int __stdcall SetConsoleCP(unsigned int);
constexpr unsigned int CP_UTF8 = 65001;
#endif

// ========================================================
// 1. 数学运算与矩阵核心
// ========================================================

// 矩阵结构体
struct Matrix {
	size_t rows, cols;
	std::vector<double> data;
	
	Matrix(size_t r = 0, size_t c = 0, double val = 0.0)
	: rows(r), cols(c), data(r * c, val) {}
	
	double& operator()(size_t r, size_t c) { return data[r * cols + c]; }
	const double& operator()(size_t r, size_t c) const { return data[r * cols + c]; }
	
	// W * x (矩阵乘向量)
	std::vector<double> operator*(const std::vector<double>& vec) const {
		std::vector<double> res(rows, 0.0);
		for (size_t i = 0; i < rows; ++i) {
			double sum = 0.0;
			for (size_t j = 0; j < cols; ++j) {
				sum += (*this)(i, j) * vec[j];
			}
			res[i] = sum;
		}
		return res;
	}
	
	// W^T * delta (转置乘向量，回传误差用)
	std::vector<double> transpose_mul(const std::vector<double>& vec) const {
		std::vector<double> res(cols, 0.0);
		for (size_t j = 0; j < cols; ++j) {
			double sum = 0.0;
			for (size_t i = 0; i < rows; ++i) {
				sum += (*this)(i, j) * vec[i];
			}
			res[j] = sum;
		}
		return res;
	}
};

// ========================================================
// 2. 神经网络层与前向/反向传播逻辑
// ========================================================

struct Layer {
	Matrix W;                    // 权重矩阵 32x32
	std::vector<double> B;       // 偏置向量 32
	
	// 缓存中间变量用于反向传播
	std::vector<double> input_cache; // 输入的 a^[l-1]
	std::vector<double> a_cache;     // 激活后的 a^[l] = tanh(W*x + B)
	
	Layer(size_t in_dim, size_t out_dim) : W(out_dim, in_dim), B(out_dim, 0.0) {}
	
	// Xavier 均匀初始化 (针对 tanh 激活函数)
	void init(std::mt19937& rng) {
		double limit = std::sqrt(6.0 / (W.rows + W.cols));
		std::uniform_real_distribution<double> dist(-limit, limit);
		for (auto& w : W.data) w = dist(rng);
		for (auto& b : B) b = 0.0;
	}
	
	// 前向传播 (使用 tanh)
	std::vector<double> forward(const std::vector<double>& in) {
		input_cache = in;
		std::vector<double> z = W * in;
		a_cache.resize(z.size());
		for (size_t i = 0; i < z.size(); ++i) {
			z[i] += B[i];
			a_cache[i] = std::tanh(z[i]); // 输出域在 (-1, 1) 之间
		}
		return a_cache;
	}
	
	// 反向传播与梯度更新
	std::vector<double> backward(const std::vector<double>& delta, double lr) {
		std::vector<double> prev_delta = W.transpose_mul(delta);
		for (size_t i = 0; i < W.rows; ++i) {
			for (size_t j = 0; j < W.cols; ++j) {
				W(i, j) -= lr * delta[i] * input_cache[j];
			}
			B[i] -= lr * delta[i];
		}
		return prev_delta;
	}
};

struct DeepNetwork32 {
	static constexpr size_t DIM = 32;
	static constexpr size_t NUM_LAYERS = 12;
	std::vector<Layer> layers;
	
	DeepNetwork32(unsigned int seed = 123) {
		std::mt19937 rng(seed);
		for (size_t i = 0; i < NUM_LAYERS; ++i) {
			Layer layer(DIM, DIM);
			layer.init(rng);
			layers.push_back(layer);
		}
	}
	
	std::vector<double> forward(const std::vector<double>& x) {
		std::vector<double> cur = x;
		for (auto& layer : layers) cur = layer.forward(cur);
		return cur;
	}
	
	double train_step(const std::vector<double>& x, const std::vector<double>& target, double lr) {
		std::vector<double> output = forward(x);
		double loss = 0.0;
		std::vector<double> delta(DIM);
		
		// 计算输出层误差，tanh 的导数为 (1 - a^2)
		for (size_t i = 0; i < DIM; ++i) {
			double err = output[i] - target[i];
			loss += 0.5 * err * err;
			double a = layers.back().a_cache[i];
			delta[i] = err * (1.0 - a * a); 
		}
		
		// 逐层回传
		for (int l = NUM_LAYERS - 1; l >= 0; --l) {
			std::vector<double> prev_delta = layers[l].backward(delta, lr);
			if (l > 0) {
				delta.resize(DIM);
				for (size_t i = 0; i < DIM; ++i) {
					double a = layers[l - 1].a_cache[i];
					delta[i] = prev_delta[i] * (1.0 - a * a); 
				}
			}
		}
		return loss;
	}
	
	bool save_model(const std::string& filepath) const {
		std::ofstream out(filepath, std::ios::binary);
		if (!out.is_open()) return false;
		for (const auto& layer : layers) {
			out.write(reinterpret_cast<const char*>(layer.W.data.data()), layer.W.data.size() * sizeof(double));
			out.write(reinterpret_cast<const char*>(layer.B.data()), layer.B.size() * sizeof(double));
		}
		return true;
	}
	
	bool load_model(const std::string& filepath) {
		std::ifstream in(filepath, std::ios::binary);
		if (!in.is_open()) return false;
		for (auto& layer : layers) {
			in.read(reinterpret_cast<char*>(layer.W.data.data()), layer.W.data.size() * sizeof(double));
			in.read(reinterpret_cast<char*>(layer.B.data()), layer.B.size() * sizeof(double));
		}
		return in.good();
	}
};

// ========================================================
// 3. UI 交互与模式控制
// ========================================================

const std::string MODEL_FILE = "deep_12l_32d_tanh.bin";
const std::string DATASET_FILE = "dataset.csv";

// 一条训练样本：输入 x (32 维) + 目标 target (32 维)
struct Sample {
	std::vector<double> x;
	std::vector<double> target;
};

// 生成示例数据集：学习 y = sin(x) 映射
// 每行 64 个浮点数，前 32 个是输入 x，后 32 个是目标 sin(x)，逗号分隔
bool generate_dataset(const std::string& filepath, size_t num_samples = 500) {
	constexpr size_t DIM = 32;
	std::ofstream out(filepath);
	if (!out.is_open()) return false;

	std::mt19937 rng(42); // 固定种子，保证每次生成的数据一致
	std::uniform_real_distribution<double> dist(-3.0, 3.0);

	out << std::fixed << std::setprecision(6);
	for (size_t s = 0; s < num_samples; ++s) {
		std::vector<double> x(DIM), target(DIM);
		for (size_t i = 0; i < DIM; ++i) {
			x[i] = dist(rng);
			target[i] = std::sin(x[i]); // 目标 = sin(输入)
		}
		// 写前 32 个输入
		for (size_t i = 0; i < DIM; ++i) {
			if (i) out << ",";
			out << x[i];
		}
		out << ",";
		// 写后 32 个目标
		for (size_t i = 0; i < DIM; ++i) {
			if (i) out << ",";
			out << target[i];
		}
		out << "\n";
	}
	return true;
}

// 从 CSV 读取数据集，每行 64 个数：前 32 输入 + 后 32 目标
bool load_dataset(const std::string& filepath, std::vector<Sample>& samples) {
	constexpr size_t DIM = 32;
	std::ifstream in(filepath);
	if (!in.is_open()) return false;

	std::string line;
	size_t line_no = 0;
	while (std::getline(in, line)) {
		++line_no;
		if (line.empty()) continue;

		std::replace(line.begin(), line.end(), ',', ' ');
		std::istringstream ss(line);
		std::vector<double> vals;
		double v;
		while (ss >> v) vals.push_back(v);

		if (vals.size() != 2 * DIM) {
			std::cerr << "× 第 " << line_no << " 行数据列数错误 (应为 " << (2 * DIM)
			<< "，实际 " << vals.size() << ")，已跳过。\n";
			continue;
		}

		Sample s;
		s.x.assign(vals.begin(), vals.begin() + DIM);
		s.target.assign(vals.begin() + DIM, vals.end());
		samples.push_back(std::move(s));
	}
	return !samples.empty();
}

void print_help() {
	std::cout << "\n=== [ 使用说明 ] ===\n"
	<< "本程序实现了一个 12 层，每层 32 维的深度全连接神经网络。\n"
	<< "网络所有激活函数均采用双曲正切(tanh)，输出平滑约束在 (-1, 1) 之间。\n"
	<< "训练任务是拟合 y = sin(x) 映射。\n\n"
	<< "[ 模式说明 ]\n"
	<< "1. 生成数据集: \n"
	<< "   随机生成 " << "500" << " 条样本写入 '" << DATASET_FILE << "'。\n"
	<< "   每行 64 个数：前 32 个是输入 x，后 32 个是目标 sin(x)。\n\n"
	<< "2. 训练模式: \n"
	<< "   从 '" << DATASET_FILE << "' 读取样本，每轮随机打乱后逐条训练。\n"
	<< "   训练完成后，权重和偏置保存到 '" << MODEL_FILE << "'。\n\n"
	<< "3. 使用模式 (推理): \n"
	<< "   从磁盘加载 '" << MODEL_FILE << "' 参数。\n"
	<< "   手动输入 32 个浮点数，网络计算 32 维输出 (应接近 sin(x))。\n\n"
	<< "注意: 请先按 [1] 生成数据集，再按 [2] 训练，最后按 [3] 推理。\n"
	<< "====================\n";
}

void run_generate_mode() {
	std::cout << "\n>>> 进入 [生成数据集模式] <<<\n";
	if (generate_dataset(DATASET_FILE)) {
		std::cout << "✓ 已生成 500 条样本并保存至: " << DATASET_FILE << "\n";
	} else {
		std::cerr << "× 生成数据集失败，请检查读写权限。\n";
	}
}

void run_train_mode() {
	std::cout << "\n>>> 进入 [训练模式] <<<\n";

	// 从文件读取数据集
	std::vector<Sample> samples;
	if (!load_dataset(DATASET_FILE, samples)) {
		std::cerr << "× 未找到数据集 '" << DATASET_FILE << "'\n"
		<< "  提示: 请先按 [1] 生成示例数据集！\n";
		return;
	}
	std::cout << "✓ 已加载 " << samples.size() << " 条训练样本。\n";

	DeepNetwork32 net;

	int epochs = 500;
	double lr = 0.005; // 12 层 tanh 网络梯度易消失，需较小学习率保证稳定下降

	std::cout << "正在训练网络 (共 " << epochs << " 轮，每轮遍历全部样本)...\n";
	std::mt19937 shuffle_rng(7); // 用于每轮随机打乱样本顺序

	for (int epoch = 1; epoch <= epochs; ++epoch) {
		std::shuffle(samples.begin(), samples.end(), shuffle_rng); // 随机打乱，避免固定顺序

		double total_loss = 0.0;
		for (const auto& s : samples) {
			total_loss += net.train_step(s.x, s.target, lr);
		}
		double avg_loss = total_loss / samples.size(); // 平均损失

		if (epoch % 20 == 0 || epoch == 1) {
			std::cout << "Epoch " << std::setw(5) << epoch
			<< " | 平均 MSE 误差: " << std::fixed << std::setprecision(6) << avg_loss << "\n";
		}
	}

	if (net.save_model(MODEL_FILE)) {
		std::cout << "\n✓ 训练完成！模型参数(12个 32x32 矩阵及偏置)已保存至: " << MODEL_FILE << "\n";
	} else {
		std::cerr << "× 保存文件失败，请检查读写权限。\n";
	}
}

void run_inference_mode() {
	constexpr size_t DIM = 32;
	std::cout << "\n>>> 进入 [推理使用模式] <<<\n";
	
	DeepNetwork32 net;
	if (!net.load_model(MODEL_FILE)) {
		std::cerr << "× 未找到模型文件 '" << MODEL_FILE << "'\n"
		<< "  提示: 请先按 [2] 运行训练模式生成参数文件！\n";
		return;
	}
	std::cout << "✓ 已成功加载 12 层网络结构参数！\n";
	std::cout << "请连续输入 32 个数值（按空格分隔，最后回车确认）:\n> ";
	
	std::vector<double> input_x(DIM);
	for (size_t i = 0; i < DIM; ++i) {
		if (!(std::cin >> input_x[i])) {
			std::cerr << "\n× 输入读取错误！必须输入恰好 32 个数值。\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			return;
		}
	}
	
	// 运行前向传播
	std::vector<double> out = net.forward(input_x);
	
	// 输出显示
	std::cout << "\n=== [ 12 层网络输出向量 (32 维) ] ===\n[ ";
	std::cout << std::fixed << std::setprecision(4);
	for (size_t i = 0; i < DIM; ++i) {
		std::cout << out[i];
		if (i + 1 < DIM) std::cout << ", ";
		if ((i + 1) % 8 == 0 && i + 1 < DIM) std::cout << "\n  "; // 每 8 个换一行方便阅读
	}
	std::cout << " ]^T\n\n";
	std::cout << "网络结构特性: 最终输出已被 tanh 函数映射，取值严格界定在 (-1.0000, 1.0000) 范围内。\n";
}

int main() {
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#endif
	while (true) {
		std::cout << "\n============================================\n";
		std::cout << "   深度神经网络原型系统 (12 层 | 32 维)\n";
		std::cout << "============================================\n";
		std::cout << " [1] 生成示例数据集 (随机生成 sin 映射样本)\n";
		std::cout << " [2] 训练模式 (读取数据集 -> 反向传播拟合 -> 存档)\n";
		std::cout << " [3] 使用模式 (读取存档 -> 手动输入 32 维向量 -> 推理)\n";
		std::cout << " [4] 查看说明文档 (Help)\n";
		std::cout << " [0] 退出程序\n";
		std::cout << "--------------------------------------------\n";
		std::cout << "请选择操作 [0-4]: ";
		
		int mode;
		if (!(std::cin >> mode)) {
			if (std::cin.eof()) {
				std::cout << "\n程序安全退出，再见！\n";
				break;
			}
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}
		
		switch (mode) {
			case 1: run_generate_mode(); break;
			case 2: run_train_mode(); break;
			case 3: run_inference_mode(); break;
			case 4: print_help(); break;
			case 0: std::cout << "程序安全退出，再见！\n"; return 0;
			default: std::cout << "× 无效的指令，请输入 0-4 之间的数字。\n";
		}
	}
	return 0;
}
