/**
 * https://leetcode.cn/problems/regular-expression-matching/
 */
#include <deque>
#include <iostream>
#include <string>

using std::string;
class Solution {
  std::deque<char> charQueue_;

public:
  bool isMatch(string s, string p) {
    buildCharStack(s);
    char lastPattern = '.';

    for (const auto &pattern : p) {
      if (charQueue_.empty() && pattern != '.' && pattern != '*' &&
          pattern != lastPattern) {
        return false;
      }
      if (pattern == '.') {
        std::cout << pattern << " killed " << charQueue_.front() << "\n";
        charQueue_.pop_front();
      } else if (pattern == '*') {
        while (!charQueue_.empty() &&
               (lastPattern == '.' || charQueue_.front() == lastPattern)) {
          std::cout << pattern << " killed " << charQueue_.front() << "\n";
          charQueue_.pop_front();
        }
      } else if (!charQueue_.empty() && charQueue_.front() == pattern) {
        std::cout << pattern << " killed " << charQueue_.front() << "\n";
        charQueue_.pop_front();
      }
      lastPattern = pattern;
    }
    if (charQueue_.empty()) {
      return true;
    } else {
      return false;
    }
  }
  void buildCharStack(const string &src) {
    for (const auto &c : src) {
      charQueue_.push_back(c);
    }
  }
};

int main() {
  Solution solution;
  if (solution.isMatch("mississippi", "mis*is*p*.")) {
    std::cout << "True";
  } else {
    std::cout << "False";
  }
}
