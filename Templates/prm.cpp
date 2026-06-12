#include <iostream>
#include <random>
#include <cmath>
#include <vector>

using namespace std;

// 模幂运算 (a^b mod n)
uint64_t mod_pow(uint64_t a, uint64_t b, uint64_t n) {
	uint64_t result = 1;
	a = a % n;
	while (b > 0) {
		if (b & 1) {
			result = (__uint128_t(result) * a) % n;
		}
		a = (__uint128_t(a) * a) % n;
		b >>= 1;
	}
	return result;
}

// Miller-Rabin 素性测试
bool is_prime(uint64_t n, int k = 10) {
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0) return false;
	
	// 将 n-1 写成 d*2^r
	uint64_t d = n - 1;
	int r = 0;
	while (d % 2 == 0) {
		d /= 2;
		r++;
	}
	
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<uint64_t> dis(2, n - 2);
	
	for (int i = 0; i < k; i++) {
		uint64_t a = dis(gen);
		uint64_t x = mod_pow(a, d, n);
		
		if (x == 1 || x == n - 1) continue;
		
		bool composite = true;
		for (int j = 0; j < r - 1; j++) {
			x = (__uint128_t(x) * x) % n;
			if (x == n - 1) {
				composite = false;
				break;
			}
		}
		if (composite) return false;
	}
	return true;
}

// 生成大质数
uint64_t generate_prime(int bits) {
	random_device rd;
	mt19937_64 gen(rd());
	
	uint64_t min_val = (bits == 64) ? (1ULL << 63) : (1ULL << (bits - 1));
	uint64_t max_val = (bits == 64) ? UINT64_MAX : (1ULL << bits) - 1;
	
	uniform_int_distribution<uint64_t> dis(min_val, max_val);
	
	uint64_t candidate;
	do {
		candidate = dis(gen);
		// 确保是奇数
		candidate |= 1;
	} while (!is_prime(candidate));
	
	return candidate;
}

int main() {
	uint64_t prime1 = generate_prime(32); // 32位质数
	uint64_t prime2 = generate_prime(32);
	
	cout << "Prime 1: " << prime1 << endl;
	cout << "Prime 2: " << prime2 << endl;
	
	return 0;
}
