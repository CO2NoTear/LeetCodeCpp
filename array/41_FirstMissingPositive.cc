#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (auto &num : nums) {
      if (num <= 0) {
        num = n + 1;
      }
    }
    for (int i = 1; i < n; ++i) {
      int index = abs(nums[i]);
      if (index <= n) {
        nums[index - 1] = -abs(nums[index - 1]);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) {
        return i + 1;
      }
    }

    return n + 1;
  }
};
