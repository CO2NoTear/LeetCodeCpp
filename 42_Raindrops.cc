#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
using namespace std;

// pair<vector<int>::iterator, vector<int>::reverse_iterator>
pair<int, int> find_range(vector<int> &water, int h_val) {
  auto left = water.begin();
  while (left != water.end()) {
    if (*left >= h_val) {
      break;
    }
    ++left;
  }
  auto right = water.rbegin();
  while (right != water.rend()) {
    if (*right >= h_val) {
      break;
    }
    ++right;
  }
  return make_pair(left - water.begin(), water.rend() - right - 1);
  // return make_pair(left, right);
}
class Solution {
public:
  int trap(vector<int> &height) {
    map<int, int> height_cnt;
    set<int> valid_heights;

    for (auto h_val : height) {
      height_cnt.emplace(h_val, 0);
      height_cnt[h_val]++;
      if (height_cnt[h_val] >= 2) {
        valid_heights.insert(h_val);
      }
    }
    vector<int> water(height);
    int max_height = *max_element(water.begin(), water.end());
    for (int h_val : valid_heights) {
      auto [left, right] = find_range(water, h_val);
      for (int i = left; i <= right; ++i) {
        water[i] = max(water[i], h_val);
      }
      cout << "height at " << h_val << ", water is :\n";
      for (auto water_h : water) {
        cout << water_h << ", ";
      }
      cout << endl;
    }
    return accumulate(water.begin(), water.end(), 0) -
           accumulate(height.begin(), height.end(), 0);
  }
};
int main() {
  vector<int> data = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  // auto [left, right] = find_range(data, 1);
  // cout << "index of left is " << data[left] << " at " << left << endl;
  // cout << "index of right is " << data[right] << " at " << right << endl;
  Solution sol;
  cout << "result = " << sol.trap(data) << endl;
}
