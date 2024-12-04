#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  set<string> dictionary;
  map<string, int> unused_words;

public:
  void build_dict(const vector<string> &words, string temp_str,
                  const int &max_length) {
    if (temp_str.length() == max_length) {
      dictionary.insert(temp_str);
      return;
    }
    for (auto next_word : words) {
      if (!unused_words[next_word])
        continue;
      unused_words[next_word] -= 1;
      build_dict(words, temp_str + next_word, max_length);
      unused_words[next_word] += 1;
    }
  }
  vector<int> findSubstring(string s, vector<string> &words) {
    int max_length = 0;
    for (auto word : words) {
      max_length += word.length();
      unused_words[word] += 1;
    }
    build_dict(words, "", max_length);
    // cout << "dictionary is: \n";
    // for (auto word : dictionary) {
    //   cout << word << ", ";
    // }
    // cout << endl;
    vector<int> indices;
    for (int i = 0; i <= max(-1, int(s.length()) - max_length); ++i) {
      string substring = s.substr(i, max_length);
      // cout << "processing substring: " << substring << endl;
      if (dictionary.count(substring)) {
        indices.push_back(i);
      }
    }
    return indices;
  }
};

int main() {
  Solution sol;
  vector<string> words{"word", "good", "best", "good"};

  vector<int> res = sol.findSubstring("wordgoodgoodgoodbestword", words);
  for (auto index : res) {
    cout << index << ", ";
  }
  cout << endl;
}
