#include <algorithm>
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::max;
using std::vector;

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    if (intervals.empty()) {
      return 0;
    }
    int n = intervals.size();

    vector<int> dp(n, 1);
    vector<int> min_interval_index_of_dp(n + 1, -1);

    // first interval form a legal solution with only 1 interval
    //      0                                        cnt
    int cnt = 1;
    min_interval_index_of_dp[cnt] = 0;

    sort(intervals.begin(), intervals.end(),
         [](const auto &u, const auto &v) { return u[0] < v[0]; });

    for (int i = 0; i < n; ++i) {
      // legal to append
      if (intervals[min_interval_index_of_dp[cnt]][1] <= intervals[i][0]) {
        min_interval_index_of_dp[++cnt] = i;
      } else {
        // try to insert
        int l = 1, r = cnt + 1, idx = 0;
        while (l < r) {
          int mid = (l + r) >> 1;
          if (intervals[min_interval_index_of_dp[mid]][0] <= intervals[i][0] &&
              intervals[min_interval_index_of_dp[mid]][1] < intervals[i][1]) {
            idx = mid;
            l = mid + 1;
          } else {
            r = mid;
          }
        }
        min_interval_index_of_dp[idx + 1] = i;
      }
      // for (int j = 0; j < i; ++j) {
      //   if (intervals[j][1] <= intervals[i][0]) {
      //     dp[i] = max(dp[i], dp[j] + 1);
      //   }
      // }
    }
    // return n - *std::max_element(dp.begin(), dp.end());
    return n - cnt;
  }
};

int main() {
  // 提供一种左闭右开的二分方法
  // vector<int> nums{1, 2, 3, 5, 6};
  // int target = 4;
  // int l = 0, r = 5, idx = 0, mid;
  // while (l < r) {
  //   mid = (l + r) >> 1;
  //   if (nums[mid] > target) {
  //     r = mid;
  //     idx = mid;
  //   } else {
  //     l = mid + 1;
  //   }
  // }
  // cout << nums[idx] << endl;
  // cout << nums[mid] << endl;
}
