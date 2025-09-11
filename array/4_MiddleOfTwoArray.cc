#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
using std::vector;

using std::cout, std::endl;
class Solution {
public:
  double getVectorKthSmallest(vector<int>::const_iterator st,
                              const vector<int>::const_iterator &ed,
                              const int &k) {
    if (ed - st < k) {
      return *st + (ed - st - 1);
    } else {
      return *(st + k - 1);
    }
  }
  double getKthSmallestWith2Vecs(const vector<int> &nums1,
                                 const vector<int> &nums2, const int &k) {
    int currentK = k;
    cout << "currentK inited as " << currentK << endl;
    if (k > nums1.size() + nums2.size()) {
      return -1;
    }
    auto st1 = nums1.begin();
    auto st2 = nums2.begin();
    while (currentK != 1 && st1 != nums1.end() && st2 != nums2.end()) {
      int actualCuttingNumel =
          std::min(std::min(static_cast<int>(nums1.end() - st1),
                            static_cast<int>(currentK / 2)),
                   std::min(static_cast<int>(nums2.end() - st2),
                            static_cast<int>(currentK / 2)));
      if (getVectorKthSmallest(st1, nums1.end(), actualCuttingNumel) <
          getVectorKthSmallest(st2, nums2.end(), actualCuttingNumel)) {
        st1 += actualCuttingNumel;
        currentK -= actualCuttingNumel;
        cout << "st1 move to " << nums1.end() - st1
             << ", currentK = " << currentK << endl;
      } else {
        st2 += actualCuttingNumel;
        currentK -= actualCuttingNumel;
        cout << "st2 move to " << nums1.end() - st1
             << ", currentK = " << currentK << endl;
      }
    }
    if (st1 == nums1.end()) {
      return getVectorKthSmallest(st2, nums2.end(), currentK);
    }
    if (st2 == nums2.end()) {
      return getVectorKthSmallest(st1, nums1.end(), currentK);
    }
    return std::min(*st1, *st2);
  }
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int totalNumel = nums1.size() + nums2.size();
    return (getKthSmallestWith2Vecs(nums1, nums2, (totalNumel + 1) / 2) +
            getKthSmallestWith2Vecs(nums1, nums2, (totalNumel + 2) / 2)) /
           2;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums1{1, 6};
  vector<int> nums2{2, 3, 4, 5, 7, 8, 9, 10};
  Solution sol;
  cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}
