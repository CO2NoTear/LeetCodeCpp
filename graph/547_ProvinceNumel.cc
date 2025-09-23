#include <cstddef>
#include <deque>
#include <vector>

using std::deque;
using std::pair;
using std::vector;

class Solution {
public:
  void bfs(vector<bool> &isColored, const vector<vector<int>> &isConnected,
           deque<size_t> q) {
    const size_t N{isConnected.size()};
    while (!q.empty()) {
      auto currentSpan = q.front();
      q.pop_front();

      for (size_t nextNode = 0; nextNode < N; ++nextNode) {
        if (!isConnected[currentSpan][nextNode] || isColored[nextNode]) {
          continue;
        } else {
          q.emplace_back(nextNode);
          isColored[nextNode] = true;
        }
      }
    }
  }
  int findCircleNum(vector<vector<int>> &isConnected) {
    const size_t N{isConnected.size()};
    vector<bool> isColored(N, false);
    int ans = 0;
    for (size_t node = 0; node < N; ++node) {
      if (!isColored[node]) {
        ++ans;
        isColored[node] = true;
        bfs(isColored, isConnected, {node});
      }
    }
    return ans;
  }
};
