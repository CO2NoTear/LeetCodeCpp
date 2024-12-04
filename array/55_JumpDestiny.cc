#include <iostream>
#include <vector>
using namespace std;

template <typename T> T min_integer(const T &a, const T &b) {
  return a < b ? a : b;
}

class Solution {
public:
  bool canJump(vector<int> &nums) {
    vector<bool> reach(nums.size());
    reach[0] = true;

    for (int i = 0; i < nums.size(); ++i) {
      if (!reach[i]) {
        return false;
      } else {
        for (int j = i + 1; j <= min_integer<int>(nums.size(), nums[i] + i);
             ++j) {
          reach[j] = true;
        }
      }
    }
    return true;
  };
};

int main() {
  vector<int> nums = {3, 2, 1, 0, 4};
  Solution sol;
  cout << (sol.canJump(nums) ? "True" : "False");
}
