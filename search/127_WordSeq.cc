#include <queue>
#include <string>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
private:
  queue<pair<string, int>> queue_;
  unordered_set<string> word_list_;
  unordered_set<string> visited_;

public:
  void generateNewWordsToQueue(string src, int step) {
    for (int i = 0; i < src.size(); ++i) {
      for (int j = 0; j < 26; ++j) {
        string des = src;
        des[i] = j + 'a';
        if (des == src || visited_.contains(des) || !word_list_.contains(des)) {
          continue;
        } else {
          queue_.push(make_pair(des, step + 1));
          visited_.insert(des);
        }
      }
    }
  }
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    if (beginWord == endWord) {
      return 2;
    }
    queue_.push(make_pair(beginWord, 1));
    word_list_ = unordered_set<string>(wordList.begin(), wordList.end());
    while (!queue_.empty()) {
      auto [new_word, step] = queue_.front();
      queue_.pop();

      if (new_word == endWord) {
        return step;
      } else {
        generateNewWordsToQueue(new_word, step);
      }
    }
    return 0;
  }
};
