#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::max;
using std::vector;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int *max_profit_when_sell_before = new int[prices.size()];
    max_profit_when_sell_before[0] = 0;
    for (int i = 1; i < prices.size(); i++) {
      max_profit_when_sell_before[i] = max_profit_when_sell_before[i - 1];

      // Sell at i
      // Buy at j
      for (int j = 0; j < i; ++j) {
        int current_gain = prices[i] - prices[j];
        max_profit_when_sell_before[i] =
            max(current_gain, max_profit_when_sell_before[i]);

        if (j - 2 >= 0) {
          cout << "j=" << j << endl;
          max_profit_when_sell_before[i] =
              max(max_profit_when_sell_before[j - 2] + current_gain,
                  max_profit_when_sell_before[i]);
        }
      }
      cout << "i = " << i << ", profit = " << max_profit_when_sell_before[i]
           << endl;
    }
    return max_profit_when_sell_before[prices.size() - 1];
  }
};
