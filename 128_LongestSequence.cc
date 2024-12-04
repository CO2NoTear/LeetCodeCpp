#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout, std::endl;
using std::max;
using std::vector, std::unordered_map;

class Solution {
  unordered_map<int, int> sum_of_num;

public:
  int longestConsecutive(vector<int> &nums) {
    int ans = 0;
    for (auto num : nums) {
      if (sum_of_num.find(num) != sum_of_num.end())
        continue;

      int left_sum = 0, right_sum = 0, current_sum;
      if (sum_of_num.find(num - 1) != sum_of_num.end()) {
        left_sum = sum_of_num[num - 1];
      }
      if (sum_of_num.find(num + 1) != sum_of_num.end()) {
        right_sum = sum_of_num[num + 1];
      }
      current_sum = left_sum + right_sum + 1;
      sum_of_num[num] = current_sum;
      ans = max(current_sum, ans);

      sum_of_num[num - left_sum] = current_sum;
      sum_of_num[num + right_sum] = current_sum;
    }
    return ans;
  }
};
