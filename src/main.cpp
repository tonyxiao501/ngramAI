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

int main() {
  system("chcp 65001");
  setlocale(LC_ALL, ""); // Set the locale to the user's default

  ifstream file("novel.txt");               // Open the file "novel.txt"
  if (!file) {                              // Check if the file was opened successfully
    cerr << "can't open novel.txt" << endl; // Print error message if file can't be opened
    return 1;                               // Exit the program with an error code
  }

  string line;                                               // String to hold each line from the file
  vector<string> words;                                      // Vector to store all words from the file
  while (getline(file, line)) {                              // Read each line from the file
    vector<string> tokens = tokenize(line);                  // Tokenize the line into words
    words.insert(words.end(), tokens.begin(), tokens.end()); // Add the tokens to the words vector
  }
  file.close(); // Close the file

  unordered_map<string, vector<string>> prediction; // Map to store word predictions
  for (size_t i = 0; i < words.size() - 2; ++i) {   // Loop through the words vector
    string key = words[i] + " " + words[i + 1];     // Create a key from two consecutive words
    prediction[key].push_back(words[i + 2]);        // Add the next word to the prediction map
  }

  vector<string> keys;                  // Vector to store all keys from the prediction map
  for (const auto& pair : prediction) { // Loop through the prediction map
    keys.push_back(pair.first);         // Add each key to the keys vector
  }

  if (keys.empty()) {                             // Check if there are no keys
    cerr << "empty key, cannot generate" << endl; // Print error message if no keys
    return 1;                                     // Exit the program with an error code
  }

  random_device rd;  // Random device for seeding
  mt19937 gen(rd()); // Mersenne Twister random number generator

  uniform_int_distribution<> key_dis(0, keys.size() - 1); // Distribution for selecting a random key
  string current = keys[key_dis(gen)];
  string sentence = current;
  for (int i = 0; i < 100; ++i) {                       // Generate up to 100 words
    if (prediction.find(current) == prediction.end()) { // Check if the current key exists in the prediction map
      cerr << "Error: key '" << current << "' not found in prediction map." << endl;
      break; // Break the loop if the key is not found
    }
    vector<string> next_words = prediction[current]; // Get the next words for the current key
    if (next_words.empty()) {
      cerr << "Error: no next words for key '" << current << "'." << endl;
      break;
    }
    uniform_int_distribution<> dis(0, next_words.size() - 1); // Distribution for selecting a random next word
    string next = next_words[dis(gen)];                       // Select a random next word
    sentence += " " + next;                                   // Add the next word to the sentence
    size_t pos = current.find(' ');                           // Find the position of the space in the current key
    if (pos == std::string::npos) {
      cerr << "Error: No space found in current key '" << current << "'." << endl;
      break;
    }
    if (pos + 1 >= current.size()) {
      cerr << "Error: Position out of range in current key '" << current << "'." << endl;
      break;
    }
    string new_key = current.substr(pos + 1) + " " + next;
    if (new_key.empty()) {
      cerr << "Error: New key is empty." << endl;
      break;
    }
    current = new_key;
  }

  cout << sentence << endl; // Print the generated sentence

  return 0; // Exit the program successfully
}