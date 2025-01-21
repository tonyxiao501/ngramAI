#include <fstream>       // For file handling
#include <iostream>      // For input and output
#include <locale>        // For locale settings
#include <random>        // For random number generation
#include <sstream>       // For string stream operations
#include <string>        // For string operations
#include <unordered_map> // For hash table (unordered_map)
#include <vector>        // For dynamic array (vector)

#include "utils.h"
#include "generate.h"
#include "tokenizer.h"

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
    } else if (arg == "--numWords" && i + 1 < argc) {
      num_words = std::max(1, std::atoi(argv[++i]));
    }
  }
  const std::string tokenFile = "tokens.dat";
  std::vector<std::string> words;
  try {
    std::ifstream tokenStream(tokenFile);
    if (!tokenStream) {
      throw std::runtime_error("无法打开 token.dat");
    }
  } catch (const std::exception& e) {
    std::cerr << "读取 tokens.dat 文件时出现异常: " << e.what() << std::endl;
    return 1;
  }

  if (doTokenize) {
    doTokenizeFunction(tokenFile, words);
  }
  if (doGenerate) {
    doGenerateFunction(words, num_words);
  }
  return 0;
}
