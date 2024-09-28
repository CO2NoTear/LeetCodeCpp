#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

/*
 * 思路：left 和
 * right分别存储，每一个left，去寻找是否有大于自己的right出现在左侧，
 * 如果有，则这个left和左侧的这个大right湮灭。
 */

// [1,3], [2,4], [3,5], []

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> sorted_intervals(intervals.begin(), intervals.end());
    sort(sorted_intervals.begin(), sorted_intervals.end()
         // ,[](vector<int> vec_a, vector<int> vec_b) {
         //   return vec_a[0] < vec_b[0];
         // });
    );
    vector<vector<int>> result;
    for (auto it = sorted_intervals.begin(); it != sorted_intervals.end();
         ++it) {
      if (result.empty() || (*it)[0] > result.back()[1]) {
        result.push_back((*it));
      } else if ((*it)[0] <= result.back()[1]) {
        result.back()[1] = max((*it)[1], result.back()[1]);
      }
    }
    return result;

    // for (int i = 0; i < sorted_intervals.size(); ++i) {
    //   cout
    // }
  }
};
int main() {
  vector<vector<int>> intervals = {{2, 6}, {1, 3},  {0, 5},  {1, 4},
                                   {4, 5}, {8, 10}, {15, 18}};
  Solution sol;
  auto merged_intervals = sol.merge(intervals);
  for (auto iterator : merged_intervals) {
    cout << "[" << iterator[0] << "," << iterator[1] << "], ";
  }
  return 0;
}
