/*
 * stable matching题目
 * 但是这题貌似只需要找到unstable pairs就行了
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl;
using std::unordered_map;
using std::vector;

template <typename DataType>
std::ostream &operator<<(std::ostream &os, const vector<DataType> &v) {
  for (auto i : v)
    cout << i << " ";
  cout << endl;
  return os;
}

class Solution {
public:
  int unhappyFriends(int n, vector<vector<int>> &preferences,
                     vector<vector<int>> &pairs) {
    int unstalbePairNumel = 0;

    vector<vector<int>> preferencesRank(n, vector<int>(n, 0));
    unordered_map<int, int> currentPairs{};

    for (int i = 0; i < n; ++i) {
      const auto &kidPreferencesList = preferences[i];
      preferencesRank[i][i] = n;
      for (int rank = 0; rank < n - 1; ++rank) {
        const auto &anotherKid = kidPreferencesList[rank];
        preferencesRank[i][anotherKid] = rank;
      }
    }
    // cout << preferencesRank;
    for (const auto &pair : pairs) {
      const auto &leftKid = pair[0];
      const auto &rightKid = pair[1];
      currentPairs[leftKid] = rightKid;
      currentPairs[rightKid] = leftKid;
    }
    for (const auto &pair : pairs) {
      const auto &leftKid = pair[0];
      const auto &rightKid = pair[1];

      auto stableMatching = [&preferencesRank, &preferences, &currentPairs](
                                const auto &leftKid, const auto &rightKid) {
        int upperboundRank = preferencesRank[leftKid][rightKid];

        vector<int> betterCandidates(preferences[leftKid].begin(),
                                     preferences[leftKid].begin() +
                                         upperboundRank);
        // cout << "(" << leftKid << ", " << rightKid << ") has a rank "
        //      << upperboundRank << " for " << leftKid << endl;

        // cout << "better candidates: " << endl << betterCandidates;

        for (auto candidateIt = preferences[leftKid].begin();
             candidateIt != preferences[leftKid].begin() + upperboundRank;
             ++candidateIt) {
          const auto &candidate = *candidateIt;
          // cout << "preferencesRank[candidate][leftKid] = "
          //      << preferencesRank[candidate][leftKid] << ", "
          //      << "preferencesRank[candidate][currentPairs[candidate]] = "
          //      << preferencesRank[candidate][currentPairs[candidate]] <<
          //      endl;
          if (preferencesRank[candidate][leftKid] <
              preferencesRank[candidate][currentPairs[candidate]]) {
            // unstalbePairNumel++;
            // break;
            return true;
          }
        }
        return false;
      };

      unstalbePairNumel += stableMatching(leftKid, rightKid);
      unstalbePairNumel += stableMatching(rightKid, leftKid);
    }
    return unstalbePairNumel;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  int n = 4;
  vector<vector<int>> preferences{
      {1, 2, 3},
      {3, 2, 0},
      {3, 1, 0},
      {1, 2, 0},
  };
  vector<vector<int>> pairs{{0, 1}, {2, 3}};
  cout << sol.unhappyFriends(n, preferences, pairs);

  return 0;
}
