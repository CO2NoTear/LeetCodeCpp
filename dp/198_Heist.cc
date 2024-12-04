#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::max;
using std::vector;

class Solution {
public:
  int rob(vector<int> &nums) {
    int *dp = new int[nums.size()];
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      dp[i] = nums[i];
      for (int j = 0; j < i - 1; ++j) {
        dp[i] = max(dp[i], dp[j] + nums[i]);
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
