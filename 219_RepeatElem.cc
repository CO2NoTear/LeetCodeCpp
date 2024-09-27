#include <cstddef>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

template <typename T> T get_min(const T &a, const T &b) {
  return a < b ? a : b;
}

using namespace std;

class Solution {
  // private:
  //   map<int, int> window_;
  //
  // public:
  // [1,2,3,1] k = 2
  //
  // Version1:
  // bool containsNearbyDuplicate(vector<int> &nums, int k) {
  //   // pre-fill
  //   for (int i = 0; i < nums.size() + k; ++i) {
  //     if (i < nums.size()) {
  //       window_.emplace(make_pair(nums[i], 0));
  //       window_[nums[i]] += 1;
  //     }
  //     if (i - k >= 0 && window_[nums[i - k]] > 1) {
  //       return true;
  //     }
  //     if (i - 2 * k >= 0) {
  //       window_[nums[i - 2 * k]] -= 1;
  //     }
  //   }
  //   return false;
  // }

  // Version2:
private:
  map<int, int> last_pos_;

public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    // pre-fill
    for (int i = 0; i < nums.size(); ++i) {
      if (last_pos_.count(nums[i]) && i - last_pos_[nums[i]] <= k) {
        return true;
      }
      last_pos_[nums[i]] = i;
    }
    return false;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 1};
  int k = 2;
  Solution sol;
  cout << sol.containsNearbyDuplicate(nums, k) << endl;
}
