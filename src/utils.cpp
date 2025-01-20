#include "utils.h"
#include <sstream>
#include <regex>

// 使用正则表达式将文本分割为更细的token（保留标点）
std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    // 匹配: 单词、标点或连续非空白字符
    std::regex tokenRegex(R"((\w+|[^\s\w]+))");
    auto wordsBegin = std::sregex_iterator(text.begin(), text.end(), tokenRegex);
    auto wordsEnd   = std::sregex_iterator();

    for (std::sregex_iterator i = wordsBegin; i != wordsEnd; ++i) {
        tokens.push_back(i->str());
    }
    return tokens;
}