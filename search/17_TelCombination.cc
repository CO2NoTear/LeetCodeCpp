#include <iostream>
#include <map>
#include <vector>

using std::cout, std::endl;
using std::map;
using std::string;
using std::vector;

class Solution {
public:
  map<char, vector<string>> dict;
  Solution() {
    dict['2'] = {"a", "b", "c"};
    dict['3'] = {"d", "e", "f"};
    dict['4'] = {"g", "h", "i"};
    dict['5'] = {"j", "k", "l"};
    dict['6'] = {"m", "n", "o"};
    dict['7'] = {"p", "q", "r", "s"};
    dict['8'] = {"t", "u", "v"};
    dict['9'] = {"w", "x", "y", "z"};
  }

  // 23
  // a|b|c + d|e|f
  void generateCase(vector<string> &answerSet, string currentStr,
                    string digitsRemained) {
    if (digitsRemained.empty()) {
      answerSet.emplace_back(currentStr);
      return;
    }
    char currentDigit = *digitsRemained.begin();
    for (const auto &newChar : dict[currentDigit]) {
      generateCase(answerSet, currentStr + newChar,
                   string(digitsRemained.begin() + 1, digitsRemained.end()));
    }
    return;
  }
  vector<string> letterCombinations(string digits) {
    vector<string> answerSet;
    if (digits.empty()) {
      return answerSet;
    }
    generateCase(answerSet, "", digits);
    return answerSet;
  }
};

int main(int argc, char *argv[]) { return 0; }
