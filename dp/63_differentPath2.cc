#include <vector>
using std::vector;
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    const size_t m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<unsigned long long>> dp(2, vector<unsigned long long>(n, 0));
    for (int i = 0; i < m; ++i) {
      int line_indicator = i & 1;
      for (int j = 0; j < n; ++j) {
        if (obstacleGrid[i][j]) {
          dp[line_indicator][j] = 0;
          continue;
        }
        if (i == 0 && j == 0) {
          dp[0][0] = 1;
          continue;
        }
        dp[line_indicator][j] = dp[line_indicator ^ 1][j];
        if (j > 0) {
          dp[line_indicator][j] += dp[line_indicator][j - 1];
        }
      }
    }
    if (obstacleGrid[m - 1][n - 1]) {
      return 0;
    }
    return dp[m & 1 ^ 1][n - 1];
  }
};
