#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using std::cout, std::endl;
using std::ostream;
using std::vector;

ostream &operator<<(ostream &os, vector<int> vec) {
  os << std::accumulate(std::next(vec.begin()), vec.end(),
                        std::to_string(*vec.begin()),
                        [](std::string a, const int &b) {
                          return std::move(a) + ", " + std::to_string(b);
                        });
  os << endl;
  return os;
}

class Solution {
public:
  int minRemoval(vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    // cout << "nums: " << nums;
    auto minRemovalWithIterators = [](auto leftIt, auto endIt,
                                      const size_t &numsSize, const double &k,
                                      auto comp) -> int {
      size_t smallestRemoval = INT_MAX;
      while (leftIt != endIt) {
        auto rightIt = std::upper_bound(leftIt, endIt, (*leftIt) * k, comp);
        if (rightIt == endIt) {
          return std::min(smallestRemoval, numsSize - (rightIt - leftIt));
        }
        smallestRemoval =
            std::min(smallestRemoval, numsSize - (rightIt - leftIt));
        // cout << "left is " << *leftIt << endl;
        // cout << "finding right is " << *rightIt << endl;
        ++leftIt;
      }
      return 0;
    };
    // cout << "starting to find smaller side:" << endl;
    int a = minRemovalWithIterators(nums.begin(), nums.end(), nums.size(), k,
                                    std::less{});
    // cout << "from smaller side: " << a << endl << endl;

    // cout << "starting to find bigger side:" << endl;
    int b = minRemovalWithIterators(nums.rbegin(), nums.rend(), nums.size(),
                                    1.0 / k, std::greater{});
    // cout << "from bigger side: " << b << endl;
    return std::min(a, b);
    // return std::min(
    //     minRemovalWithIterators(nums.begin(), nums.end(), nums.size()),
    //     minRemovalWithIterators(nums.rbegin(), nums.rend(), nums.size()));
  }
};
