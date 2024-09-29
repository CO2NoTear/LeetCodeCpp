#include <vector>
using namespace std;
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int last_val = -0x7fffffff;
    int cnt = 0;
    auto it = nums.begin();
    while (it != nums.end()) {
      if (*it != last_val) {
        last_val = *it;
        cnt = 0;
      }
      cnt++;
      if (cnt > 2) {
        it = nums.erase(it);
      } else {
        ++it;
      }
    }
    return nums.size();
  }
};
