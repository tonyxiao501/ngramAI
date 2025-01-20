#include <fstream>       // For file handling
#include <iostream>      // For input and output
#include <locale>        // For locale settings
#include <random>        // For random number generation
#include <sstream>       // For string stream operations
#include <string>        // For string operations
#include <unordered_map> // For hash table (unordered_map)
#include <vector>        // For dynamic array (vector)

#include "utils.h"

using namespace std;

int main(int argc, char* argv[]) {
  bool doTokenize = false;
  bool doGenerate = false;
  int num_words = 100;

  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "--tokenize") {
      doTokenize = true;
    } else if (arg == "--generate") {
      doGenerate = true;
    } else if (arg == "--numWords" && i + 1 < argc){
      num_words = std::max(1, std::atoi(argv[++i]));
    }
  }

  system("chcp 65001");
  setlocale(LC_ALL, ""); // 设置为用户的默认区域设置

  const std::string tokenFile = "tokens.dat";
  vector<string> words;

  ifstream tokenStream(tokenFile);

  if (doTokenize) {
    ifstream file("novel.txt");             // 打开 "novel.txt" 文件
    if (!file) {                            // 检查文件是否成功打开
      cerr << "无法打开 novel.txt" << endl; // 如果无法打开文件，输出错误信息
      return 1;                             // 以错误代码退出程序
    }

    string line;                                               // 用于存储文件中的每一行
    while (getline(file, line)) {                              // 读取文件中的每一行
      vector<string> tokens = tokenize(line);                  // 将行内容进行tokenize
      words.insert(words.end(), tokens.begin(), tokens.end()); // 将token添加到words向量中
    }
    file.close(); // 关闭文件

    // 将tokenize后的单词保存到文件
    ofstream outToken(tokenFile);
    if (!outToken) {
      cerr << "无法创建 " << tokenFile << endl;
      return 1;
    }
    for (const auto& word : words) {
      outToken << word << "\n";
    }
    outToken.close();
    cout << "已将tokenized的单词保存到 " << tokenFile << "。" << endl;
    //}
  }
  if (doGenerate) {
    ifstream tokenStream(tokenFile);
    if (!tokenStream){
      cerr << tokenFile << "不存在，无法生成" << endl;
      return 1;
    }
    string word;
    while (getline(tokenStream, word)) {
      words.push_back(word);
    }
    tokenStream.close();
    if (words.size() < 3) {
      cerr << "单词数量不足以构建预测模型。" << endl;
      return 1;
    }

    unordered_map<string, vector<string>> prediction; // 用于存储单词预测的映射
    for (size_t i = 0; i < words.size() - 2; ++i) {   // 遍历words向量
      string key = words[i] + " " + words[i + 1];     // 用两个连续的单词创建键
      prediction[key].push_back(words[i + 2]);        // 将下一个单词添加到预测映射中
    }

    vector<string> keys;                  // 用于存储所有键的向量
    for (const auto& pair : prediction) { // 遍历预测映射
      keys.push_back(pair.first);         // 将每个键添加到keys向量中
    }

    if (keys.empty()) {                           // 检查是否存在键
      cerr << "没有可用的键，无法生成。" << endl; // 如果没有键，输出错误信息
      return 1;                                   // 以错误代码退出程序
    }

    random_device rd;                                   // 随机设备用于种子生成
    mt19937 gen(rd());                                  // Mersenne Twister随机数生成器
    uniform_int_distribution<> dis(0, keys.size() - 1); // 均匀分布用于键选择

    // 选择一个随机的起始键
    string current_key = keys[dis(gen)];
    cout << "起始键: " << current_key << endl;
    cout << "生成文本(共 " << num_words << " 个单词）:" << endl;
    cout << current_key << " ";

    for (int i = 0; i < num_words; ++i) {
      if (prediction.find(current_key) == prediction.end()) {
        break; // 如果当前键没有预测，终止生成
      }
      const vector<string>& possible_next = prediction[current_key];
      uniform_int_distribution<> next_dis(0, possible_next.size() - 1);
      string next_word = possible_next[next_dis(gen)];
      cout << next_word << " ";
      // 更新当前键，移除第一个单词并添加下一个单词
      size_t space_pos = current_key.find(' ');
      if (space_pos != string::npos) {
        current_key = current_key.substr(space_pos + 1) + " " + next_word;
      } else {
        current_key = next_word;
      }
    }
    cout << endl;
  }
  return 0;
}