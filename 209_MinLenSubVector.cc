#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int sum = 0;
    int st = 0, ed = 0;
    const int MAX_LEN = 0x7fffffff;
    int min_len = MAX_LEN;
    while (sum < target && ed < nums.size()) {
      sum += nums[ed++];
    }
    if (sum < target) {
      return 0;
    }
    while (ed < nums.size()) {

      while (sum - nums[st] >= target && st < ed) {
        sum -= nums[st++];
      }
      if (ed - st < min_len) {
        min_len = min(min_len, ed - st);
        cout << ed << "," << st << ":" << min_len << endl;
      }

      sum += nums[ed++];
    }
    return min_len;
  }
};

int main() {
  int target = 11;
  vector<int> nums = {1, 2, 3, 4, 5};
  Solution sol;
  cout << sol.minSubArrayLen(target, nums);
}
