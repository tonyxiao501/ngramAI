#include <fstream>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <random>

#include "tokenizer.h"
#include "utils.h"

const std::string tokenFile = "tokens.dat";
void doGenerateFunction(std::vector<std::string>& words, int num_words) {
  try {
    std::ifstream tokenStream(tokenFile);
    if (!tokenStream) {
      throw std::runtime_error(tokenFile + "不存在，无法生成");
    }
    std::string word;
    while (getline(tokenStream, word)) {
      words.push_back(word);
    }
    tokenStream.close();
    if (words.size() < 3) {
      throw std::runtime_error("单词数量不足以构建预测模型。");
    }
    if (num_words <= 0) {
      throw std::invalid_argument("num_words 必须是一个正整数");
    }
  } catch (const std::exception& e) {
    std::cerr << "错误: " << e.what() << std::endl;
  }

  std::unordered_map<std::string, std::vector<std::string>> prediction; // 用于存储单词预测的映射
  for (size_t i = 0; i < words.size() - 2; ++i) {                       // 遍历words向量
    std::string key = words[i] + " " + words[i + 1];                    // 用两个连续的单词创建键
    prediction[key].push_back(words[i + 2]);                            // 将下一个单词添加到预测映射中
  }

  std::vector<std::string> keys;        // 用于存储所有键的向量
  for (const auto& pair : prediction) { // 遍历预测映射
    keys.push_back(pair.first);         // 将每个键添加到keys向量中
  }

  if (keys.empty()) {                                     // 检查是否存在键
    std::cerr << "没有可用的键，无法生成。" << std::endl; // 如果没有键，输出错误信息
  }

  std::random_device rd;                                   // 随机设备用于种子生成
  std::mt19937 gen(rd());                                  // Mersenne Twister随机数生成器
  std::uniform_int_distribution<> dis(0, keys.size() - 1); // 均匀分布用于键选择

  // 选择一个随机的起始键
  std::string current_key = keys[dis(gen)];
  std::cout << "起始键: " << current_key << std::endl;
  std::cout << "生成文本(共 " << num_words << " 个单词）:" << std::endl;
  std::cout << current_key << " ";

  for (int i = 0; i < num_words; ++i) {
    if (prediction.find(current_key) == prediction.end()) {
      break; // 如果当前键没有预测，终止生成
    }
    const std::vector<std::string>& possible_next = prediction[current_key];
    std::uniform_int_distribution<> next_dis(0, possible_next.size() - 1);
    std::string next_word = possible_next[next_dis(gen)];
    std::cout << next_word << " ";
    // 更新当前键，移除第一个单词并添加下一个单词
    size_t space_pos = current_key.find(' ');
    if (space_pos != std::string::npos) {
      current_key = current_key.substr(space_pos + 1) + " " + next_word;
    } else {
      current_key = next_word;
    }
  }
  std::cout << std::endl;
}