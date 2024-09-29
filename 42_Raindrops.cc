#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

pair<vector<int>::iterator, vector<int>::reverse_iterator>
find_range(vector<int> &water, int h_val) {
  auto left = water.begin();
  while (left != water.end()) {
    if (*left == h_val) {
      break;
    }
    ++left;
  }
  auto right = water.rbegin();
  while (right != water.rend()) {
    if (*right == h_val) {
      break;
    }
    ++right;
  }
  // return make_pair(water.end() - left, water.rend() - right);
  return make_pair(left, right);
}
class Solution {
public:
  int trap(vector<int> &height) {
    vector<int> water(height);
    int max_height = *max_element(water.begin(), water.end());
    for (int h_val = 1; h_val <= max_height; ++h_val) {
      for (auto it = left; it != right.base(); ++it) {
        *it = h_val;
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
  vector<int> data = {1, 2, 3, 4, 5, 5, 7, 8, 9};
  auto [left, right] = find_range(data, 5);
  cout << "index of left is " << *left << " at " << data.end() - left - 1
       << endl;
  cout << "index of right is " << *(right - 1) << " at "
       << data.rend() - right - 1 << endl;
}
