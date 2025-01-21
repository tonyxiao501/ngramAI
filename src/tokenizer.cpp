#include "tokenizer.h"
#include "utils.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

void doTokenizeFunction(const std::string& tokenFile, std::vector<std::string>& words) {
  try {
    std::ifstream file("novel.txt");
    if (!file) {
      throw std::runtime_error("无法打开 novel.txt");
    }
    std::string line;
    while (getline(file, line)) {
      std::vector<std::string> tokens = tokenize(line);
      words.insert(words.end(), tokens.begin(), tokens.end());
    }
    file.close();
  } catch (const std::exception& e) {
    std::cerr << "读取文件出现异常: " << e.what() << std::endl;
  }
  std::ofstream outToken;
  try {
    outToken.open(tokenFile);
    if (!outToken) {
      throw std::runtime_error("无法创建 " + tokenFile);
    }
  } catch (const std::exception& e) {
    std::cerr << "错误: " << e.what() << std::endl;
  }
  for (const auto& word : words) {
    outToken << word << "\n";
  }
  outToken.close();
  std::cout << "已将tokenized的单词保存到 " << tokenFile << "。" << std::endl;
}