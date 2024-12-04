#include <iostream>
#include <vector>

using namespace std;

// Version1: Brute Force
// 数据规模太大的4个点过不了
//
// #include <algorithm>
// #include <map>
// #include <numeric>
// #include <set>
// #include <utility>
// pair<int, int> find_range(vector<int> &water, int h_val) {
//   auto left = water.begin();
//   while (left != water.end()) {
//     if (*left >= h_val) {
//       break;
//     }
//     ++left;
//   }
//   auto right = water.rbegin();
//   while (right != water.rend()) {
//     if (*right >= h_val) {
//       break;
//     }
//     ++right;
//   }
//   return make_pair(left - water.begin(), water.rend() - right - 1);
//   // return make_pair(left, right);
// }
// class Solution {
// public:
//   int trap(vector<int> &height) {
//     map<int, int> height_cnt;
//     set<int> valid_heights;
//
//     for (auto h_val : height) {
//       height_cnt.emplace(h_val, 0);
//       height_cnt[h_val]++;
//       if (height_cnt[h_val] >= 2) {
//         valid_heights.insert(h_val);
//       }
//     }
//     vector<int> water(height);
//     int max_height = *max_element(water.begin(), water.end());
//     for (int h_val : valid_heights) {
//       auto [left, right] = find_range(water, h_val);
//       for (int i = left; i <= right; ++i) {
//         water[i] = max(water[i], h_val);
//       }
//       cout << "height at " << h_val << ", water is :\n";
//       for (auto water_h : water) {
//         cout << water_h << ", ";
//       }
//       cout << endl;
//     }
//     return accumulate(water.begin(), water.end(), 0) -
//            accumulate(height.begin(), height.end(), 0);
//   }
// };

// Version2: decreasing Stack
#include <deque>
#include <stack>
class Solution {
private:
  stack<int> left_walls_index;

  int push_wall(const vector<int> &height, int right_index) {
    // cout << "trying to process right_index of " << right_index << endl;
    if (left_walls_index.size() < 2 ||
        height[right_index] < height[left_walls_index.top()]) {
      left_walls_index.push(right_index);
      return 0;
    } else {
      // cout << "before calc, stack is :\n";
      // stack<int> temp(left_walls_index);
      // while (!temp.empty()) {
      //   cout << temp.top() << " >> ";
      //   temp.pop();
      // }
      // cout << "||\n";
      int bottom_index = left_walls_index.top();
      left_walls_index.pop();
      int left_index = left_walls_index.top();
      int water_volume = max(min(height[left_index], height[right_index]) -
                                 height[bottom_index],
                             0) *
                         (right_index - left_index - 1);
      // cout << "after calc, stack is :\n";
      stack<int> temp2(left_walls_index);
      // while (!temp2.empty()) {
      // cout << temp2.top() << " >> ";
      //   temp2.pop();
      // }
      // cout << "||\n";
      // cout << "added " << water_volume << endl;
      return water_volume + push_wall(height, right_index);
    }
  }

public:
  int trap(vector<int> &height) {

    int result = 0;
    for (int i = 0; i < height.size(); ++i) {
      result += push_wall(height, i);
    }
    return result;
  }
};
int main() {
  // Case1:
  // vector<int> data = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  // Case2:
  vector<int> data = {4, 2, 0, 3, 2, 5};
  // auto [left, right] = find_range(data, 1);
  // cout << "index of left is " << data[left] << " at " << left << endl;
  // cout << "index of right is " << data[right] << " at " << right << endl;
  Solution sol;
  cout << "result = " << sol.trap(data) << endl;
}
