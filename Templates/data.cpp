#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <string>

using namespace std;


void generate_data(int file_idx) {
	mt19937_64 rng(time(0) + file_idx); // 增加随机偏移
	
	string in_name = "data" + to_string(file_idx) + ".in";
	ofstream fout(in_name, ios::binary); // 二进制模式保证 LF
	
	// 洛谷范围设定
	long long max_nm = 1000000000LL; 
	long long max_kt = 1000000LL;
	
	// 每个输入文件包含 1 组数据（方便设置子任务或单独测试点）
	long long t = rng() % max_kt + 1;
	long long k = rng() % (max_kt - t + 1) + t;
	long long m = rng() % (max_nm - k + 1) + k;
	long long n = rng() % max_nm + 1;
	
	// 构造输出字符串并确保末尾是 \n
	string content = to_string(n) + " " + to_string(m) + " " + 
	to_string(k) + " " + to_string(t) + "\n";
	fout.write(content.c_str(), content.size());
	
	fout.close();
	cout << "Generated: " << in_name << endl;
}

int main() {
	int num_tests = 10; // 生成 10 对测试点
	for(int i = 1; i <= num_tests; i++) {
		generate_data(i);
	}
	return 0;
}
