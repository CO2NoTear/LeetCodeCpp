#include <iostream>
using std::cout, std::endl;
#include <numeric>
#include <vector>
using std::pair;
using std::vector;

class Solution {
public:
  const vector<pair<int, int>> directions_{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  size_t gridRows_, gridCols_;
  unsigned long long fullSteps_;

  template <typename T>
  pair<int, int> findItemIn2DVector(vector<vector<T>> &grid, const T &item) {
    for (auto line_it = grid.begin(); line_it != grid.end(); ++line_it) {
      const auto &line = *line_it;
      for (auto elem_it = line.begin(); elem_it != line.end(); ++elem_it) {
        const auto &elem = *elem_it;
        if (elem == item) {
          return {line_it - grid.begin(), elem_it - line.begin()};
        }
      }
    }
    return {-1, -1};
  }
  int uniquePathsIII(vector<vector<int>> &grid) {
    gridRows_ = grid.size();
    gridCols_ = grid[0].size();
    auto startCoords = findItemIn2DVector(grid, 1);
    auto endCoords = findItemIn2DVector(grid, 2);
    // cout << "startCoords = " << startCoords.first << ", " <<
    // startCoords.second
    //      << endl;
    // cout << "endCoords = " << endCoords.first << ", " << endCoords.second
    //      << endl;
    size_t obstacleNumel = 0;
    for (const auto &line : grid) {
      obstacleNumel = std::accumulate(line.begin(), line.end(), obstacleNumel,
                                      [](const auto res, const auto &item) {
                                        if (item == -1)
                                          return std::move(res) + 1;
                                        else
                                          return std::move(res);
                                      });
    }
    fullSteps_ = gridRows_ * gridCols_ - obstacleNumel;
    auto visited =
        vector<vector<bool>>(gridRows_, vector<bool>(gridCols_, false));
    visited[startCoords.first][startCoords.second] = true;

    for (auto line_it = grid.begin(); line_it != grid.end(); ++line_it) {
      const auto &line = *line_it;
      for (auto elem_it = line.begin(); elem_it != line.end(); ++elem_it) {
        const auto &elem = *elem_it;
        if (elem == -1) {
          visited[line_it - grid.begin()][elem_it - line.begin()] = true;
        }
      }
    }

    return dfs(visited, 1, startCoords, endCoords);
  }
  bool inBound(pair<int, int> coords) {
    if (coords.first < 0 || coords.first >= gridRows_) {
      return false;
    }
    if (coords.second < 0 || coords.second >= gridCols_) {
      return false;
    }
    return true;
  }
  int dfs(vector<vector<bool>> &visited, int step, pair<int, int> coords,
          const pair<int, int> &endCoords) {
    // cout << "currentCoords = " << coords.first << ", " << coords.second <<
    // endl;
    if (coords == endCoords && step == fullSteps_) {
      return 1;
    }
    int ans = 0;
    for (const auto &direction : directions_) {
      pair<int, int> newCoords = {coords.first + direction.first,
                                  coords.second + direction.second};
      if (inBound(newCoords) && !visited[newCoords.first][newCoords.second]) {
        visited[newCoords.first][newCoords.second] = true;
        ans += dfs(visited, step + 1, newCoords, endCoords);
        visited[newCoords.first][newCoords.second] = false;
      }
    }
    return ans;
  }
};
