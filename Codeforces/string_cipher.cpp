#include <cctype>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

// 使用密钥的字节循环异或。再次使用同一密钥即可还原原文。
std::string xorWithKey(const std::string& data, const std::string& key) {
    if (key.empty()) {
        throw std::invalid_argument("密钥不能为空");
    }

    std::string result(data.size(), '\0');
    for (std::size_t i = 0; i < data.size(); ++i) {
        result[i] = static_cast<char>(
            static_cast<unsigned char>(data[i]) ^
            static_cast<unsigned char>(key[i % key.size()]));
    }
    return result;
}

std::string toHex(const std::string& data) {
    std::ostringstream out;
    out << std::hex << std::setfill('0');
    for (unsigned char byte : data) {
        out << std::setw(2) << static_cast<unsigned int>(byte);
    }
    return out.str();
}

int hexValue(char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
    if (ch >= 'a' && ch <= 'f') return ch - 'a' + 10;
    return -1;
}

std::string fromHex(const std::string& hex) {
    if (hex.size() % 2 != 0) {
        throw std::invalid_argument("十六进制密文的长度必须是偶数");
    }

    std::string data;
    data.reserve(hex.size() / 2);
    for (std::size_t i = 0; i < hex.size(); i += 2) {
        const int high = hexValue(hex[i]);
        const int low = hexValue(hex[i + 1]);
        if (high < 0 || low < 0) {
            throw std::invalid_argument("密文只能包含 0-9、a-f 或 A-F");
        }
        data.push_back(static_cast<char>((high << 4) | low));
    }
    return data;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    std::cout << "字符串密钥加密/解密工具\n"
              << "1. 加密\n"
              << "2. 解密\n"
              << "请选择（1 或 2）：";

    std::string choice;
    std::getline(std::cin, choice);

    try {
        std::string key;
        if (choice == "1") {
            std::string plainText;
            std::cout << "请输入要加密的字符串：";
            std::getline(std::cin, plainText);
            std::cout << "请输入密钥：";
            std::getline(std::cin, key);

            const std::string encrypted = xorWithKey(plainText, key);
            std::cout << "加密结果（十六进制）：" << toHex(encrypted) << '\n';
        } else if (choice == "2") {
            std::string cipherHex;
            std::cout << "请输入十六进制密文：";
            std::getline(std::cin, cipherHex);
            std::cout << "请输入密钥：";
            std::getline(std::cin, key);

            const std::string decrypted = xorWithKey(fromHex(cipherHex), key);
            std::cout << "解密结果：" << decrypted << '\n';
        } else {
            std::cerr << "无效选择，请输入 1 或 2。\n";
            return 1;
        }
    } catch (const std::exception& error) {
        std::cerr << "错误：" << error.what() << '\n';
        return 1;
    }

    return 0;
}
