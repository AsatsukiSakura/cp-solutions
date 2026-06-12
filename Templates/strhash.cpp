#include <iostream>
#include <string>

using ll=long long;
const ll mod=998244353;
ll simpleHash(const std::string& str) {
	ll hash = 0;
	for (char c : str) {
		hash = hash * 104857601 + c;
		hash%=mod;
	}
	return hash*888888887%mod;
}

int main() {
	int n;
	std::cout << "请输入要哈希的字符串数量: ";
	std::cin >> n;
	std::cin.ignore();
	
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cout << "输入字符串 " << i + 1 << ": ";
		std::getline(std::cin, str);
		std::cout << "哈希值: " << simpleHash(str) << std::endl;
	}
	
	return 0;
}
