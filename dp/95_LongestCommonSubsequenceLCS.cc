#include <vector>
using std::string;
using std::vector;

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> LCS(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 0; i < text1.size(); ++i) {
      for (int j = 0; j < text2.size(); ++j) {
        if (text1.at(i) == text2.at(j)) {
          LCS[i + 1][j + 1] = LCS[i][j] + 1;
        } else {
          LCS[i + 1][j + 1] = std::max(LCS[i + 1][j], LCS[i][j + 1]);
        }
      }
    }
    return LCS[text1.size()][text2.size()];
  }
};
