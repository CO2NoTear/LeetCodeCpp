#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  unordered_map<char, int> dict_, standard_;
  bool good_str(const string &str) {
    for (const auto &pair : standard_) {
      if (dict_[pair.first] < pair.second) {
        return false;
      }
    }
    return true;
  }
  string minWindow(string s, string t) {
    for (const char &c : t) {
      standard_[c]++;
    }
    int st = 0, ed = 0;
    int ans_left = -1, ans_len = 0;

    while (ed < s.size()) {
      if (standard_.find(s[ed]) != standard_.end()) {
        ++dict_[s[ed]];
      }
      ++ed;
      while (good_str(t) && st < ed) {
        if (ans_left == -1 || ans_len > ed - st) {
          ans_len = ed - st;
          ans_left = st;
        }
        char cur_char = s[st++];
        if (standard_.find(cur_char) != standard_.end()) {
          --dict_[cur_char];
        }
      }
    }
    return ans_left == -1 ? string("") : s.substr(ans_left, ans_len);
  }
};

int main() {
  string s1 = "ADOBECODEBANC", s2 = "ABC";
  Solution sol;
  cout << sol.minWindow(s1, s2) << endl;
}
