#include <iostream>
#include <string>
#include <regex>
#include <vector>

/**
 * 闪灯杯 MP ID 提取器
 * 功能：从粘贴的杂乱文本中自动识别并提取 osu.ppy.sh 的比赛 ID
 */

int main() {
	// 提示信息（输出到 stderr 不影响结果提取）
	std::clog << "请粘贴包含比赛记录的文本 (完成后按 Ctrl+Z 并回车结束输入):" << std::endl;
	
	std::string line;
	std::string full_text;
	
	// 循环读取所有输入的行
	while (std::getline(std::cin, line)) {
		full_text += line + "\n";
	}
	
	// 正则表达式：匹配 matches/ 或 mp/ 后面的数字
	// (?:...) 是非捕获组，([0-9]+) 是捕获组 1
	std::regex mp_regex(R"((?:matches/|mp/)([0-9]+))");
	
	std::smatch matches;
	std::string::const_iterator searchStart(full_text.cbegin());
	
	std::cout << "\n--- 提取到的 MP ID 列表 ---" << std::endl;
	
	bool found = false;
	while (std::regex_search(searchStart, full_text.cend(), matches, mp_regex)) {
		// matches[1] 对应 ([0-9]+) 抓取到的数字部分
		std::cout << matches[1].str() << std::endl;
		searchStart = matches.suffix().first;
		found = true;
	}
	
	if (!found) {
		std::cout << "未在输入中找到任何有效 MP 链接。" << std::endl;
	}
	
	return 0;
}
