#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// 使用 __int128 处理可能爆炸的指数级项数
typedef __int128_t int128;

// 将 __int128 转换为字符串以便输出
string int128ToString(int128 n) {
	if (n == 0) return "0";
	string s = "";
	while (n > 0) {
		s += (char)('0' + (n % 10));
		n /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

// 计算 Euler's Totient 函数 phi(n)
int getPhi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			result -= result / i;
		}
	}
	if (n > 1) result -= result / n;
	return result;
}

// 获取 phi(n) 的素因子分解（决定域扩张塔的每一层）
vector<int> getPrimeFactors(int n) {
	vector<int> factors;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			factors.push_back(i);
			n /= i;
		}
	}
	if (n > 1) factors.push_back(n);
	return factors;
}

// 高精度组合数计算
int128 nCr(int n, int r) {
	if (r > n) return 0;
	if (r == 0 || r == n) return 1;
	if (r > n / 2) r = n - r;
	int128 res = 1;
	for (int i = 1; i <= r; ++i) {
		res = res * (n - i + 1) / i;
	}
	return res;
}

int main() {
	int n;
	cout << "请输入阶数 n (例如 7, 11, 31...): ";
	while (cin >> n && n > 0) {
		if (n == 1) {
			cout << "zeta_1 = 1 (信息量: 1)" << endl;
			continue;
		}
		
		int phi = getPhi(n);
		vector<int> factors = getPrimeFactors(phi);
		
		int128 complexity = phi; // 基础项数
		for (int p : factors) {
			complexity *= nCr(2 * p - 1, p - 1);
		}
		
		cout << "\n--- 分析结果 ---" << endl;
		cout << "扩张次数 phi(n) = " << phi << endl;
		cout << "分解路径 (Tower): ";
		for (size_t i = 0; i < factors.size(); ++i) {
			cout << factors[i] << (i == factors.size() - 1 ? "" : " -> ");
		}
		cout << "\n展开后的纯根式项数: " << int128ToString(complexity) << endl;
		
		// 规模评估
		if (complexity < 1000) cout << "评价: 可以在一张纸上写完。" << endl;
		else if (complexity < 1000000) cout << "评价: 相当于一本厚书的信息量。" << endl;
		else if (complexity < 1000000000000ULL) cout << "评价: 需要一个图书馆的存储容量。" << endl;
		else cout << "评价: 已超越人类文明的文本承载极限。" << endl;
		
		cout << "\n请输入下一个 n (或按 Ctrl+C 退出): ";
	}
	return 0;
}
