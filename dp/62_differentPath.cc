#include <vector>
using std::vector;
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<unsigned long long>> dp(2, vector<unsigned long long>(n, 0));
    dp[1][0] = 1;
    for (int i = 0; i < m; ++i) {
      int line_indicator = i & 1;
      for (int j = 0; j < n; ++j) {
        dp[line_indicator][j] = dp[line_indicator ^ 1][j];
        if (j > 0) {
          dp[line_indicator][j] += dp[line_indicator][j - 1];
        }
      }
    }
    return dp[m & 1 ^ 1][n - 1];
  }
};
