#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
  void rotate(vector<int> &nums, int k) {

    // Version 1:
    // 划分等价类，循环交换
    // for (int group = 0; group < std::gcd(nums.size(), k); ++group) {
    //   for (int i = 0; i < nums.size() / std::gcd(nums.size()-1, k); i++) {
    //     int temp = nums[(group + k * nums.size() - i * k) % nums.size()];
    //     nums[group + (k * nums.size() - i * k) % nums.size()] =
    //         nums[group + (k * nums.size() - (i - 1) * k) % nums.size()];
    //     nums[group + (k * nums.size() - (i - 1) * k) % nums.size()] = temp;
    //   }
    // }
    //

    // Version 2:
    // Reverse 申必手法

    // 先全部反转
    reverse(nums.begin(), nums.end());
    // 反转被右移到前面的那串
    reverse(nums.begin(), nums.begin() + k);
    // 反转被右移到后面的那串
    reverse(nums.begin() + k, nums.end());
  }
};
