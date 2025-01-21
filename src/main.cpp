#include <fstream>     
#include <iostream>      
#include <locale>       
#include <random>        
#include <sstream>     
#include <string>       
#include <unordered_map> 
#include <vector>        

#include "utils.h"
#include "generate.h"
#include "tokenizer.h"

int main(int argc, char* argv[]) {
  bool doTokenize = false;
  bool doGenerate = false;
  int num_words = 100;

  if (argc == 1) {
    std::cout << "Usage: " << argv[0] << " [--tokenize] [--generate] [--numWords <number>]\n";
    return 0;
  }
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

  if (doTokenize) {
    doTokenizeFunction(tokenFile, words);
  }
  if (doGenerate) {
    doGenerateFunction(words, num_words);
  }
  return 0;
}
