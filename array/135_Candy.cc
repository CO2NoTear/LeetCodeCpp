#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
  int candy(vector<int> &ratings) {
    vector<int> candy(ratings.size(), 1);

    cout << "left:" << endl;
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) {
        candy[i] = candy[i - 1] + 1;
      }
    }
    for (auto it : candy) {
      cout << it << ", ";
    }
    cout << endl;
    cout << "right:" << endl;
    for (int i = ratings.size() - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        candy[i] = max(candy[i], candy[i + 1] + 1);
      }
    }
    for (auto it : candy) {
      cout << it << ", ";
    }
    cout << endl;
    return accumulate(candy.begin(), candy.end(), 0);
  }
};

int main() {
  vector<int> ratings{1, 3, 4, 5, 2};
  Solution sol;
  sol.candy(ratings);
}
