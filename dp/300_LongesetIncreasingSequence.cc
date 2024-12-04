#include <algorithm>
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::max;
using std::vector;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> min_num_of_len(nums.size() + 1, 0);
    int max_len = 1;
    min_num_of_len[max_len] = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      cout << "i=" << i << ", max_len= " << max_len
           << ", min_num_of_len[max_len]= " << min_num_of_len[max_len] << endl;
      if (min_num_of_len[max_len] < nums[i]) {
        min_num_of_len[++max_len] = nums[i];
      } else {
        // try to insert into a best len position
        // default pos is len at 1, which is the beginning
        int l = 1, r = max_len + 1, pos = 0;
        while (l < r) {
          int mid = (l + r) >> 1;
          if (min_num_of_len[mid] < nums[i]) {
            // can append behind pos
            pos = mid;
            l = mid + 1;
          } else {
            r = mid;
          }
        }
        min_num_of_len[pos + 1] = nums[i];
      }
    }
    return max_len;
  }
};
