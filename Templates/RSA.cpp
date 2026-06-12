#include <iostream>
#include <string>
#include <vector>

// 快速幂：计算 (base^exp) % mod
int quick_pow(int base, int exp, int mod) {
	int res = 1;
	base %= mod;
	while (exp > 0) {
		if (exp % 2 == 1) res = (res * base) % mod;
		base = (base * base) % mod;
		exp /= 2;
	}
	return res;
}

class Cipher143 {
private:
	int map[143];
	
public:
	Cipher143() {
		// 预处理 0-142 的所有结果
		for (int i = 0; i < 143; ++i) {
			map[i] = quick_pow(i, 11, 143);
		}
	}
	
	std::string transform(const std::string& input) {
		std::string output = input;
		for (char &c : output) {
			unsigned char uc = static_cast<unsigned char>(c);
			if (uc < 143) {
				c = static_cast<char>(map[uc]);
			}
			// 如果 utf >= 143，则保持原样（虽然无法解密，但保证程序不崩）
		}
		return output;
	}
};

int main() {
	Cipher143 cipher;
	
	std::string raw = "Hello RSA 143!";
	std::string encrypted = cipher.transform(raw);
	std::string decrypted = cipher.transform(encrypted);
	
	std::cout << "Raw:       " << raw << std::endl;
	std::cout << "Encrypted: " << encrypted << std::endl;
	std::cout << "Decrypted: " << decrypted << std::endl;
	
	return 0;
}
