#include <vector>
using std::vector;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    auto layerItReversed = triangle.rbegin();
    const auto &lastLayer = *layerItReversed;
    vector<int> currentCosts(lastLayer.size() + 1, 0);
    while (layerItReversed != triangle.rend()) {
      const auto &currentLayer = *layerItReversed++;
      for (size_t i = 0; i < currentLayer.size(); ++i) {
        currentCosts[i] =
            currentLayer[i] + std::min(currentCosts[i], currentCosts[i + 1]);
      }
    }
    return currentCosts[0];
  }
};
