#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
      auto left = lower_bound(numbers.begin(), numbers.begin() + i,
                              target - numbers[i]);
      if (*left + numbers[i] == target) {
        return vector<int>{*left, numbers[i]};
      }
    }
    return vector<int>();
  }
};
