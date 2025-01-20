#include "utils.h"
#include <sstream>

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::string word;
    std::stringstream ss(text);
    while (ss >> word) {
        tokens.push_back(word);
    }
    return tokens;
}