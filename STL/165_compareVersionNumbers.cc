#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>
using std::cout, std::endl;
using std::ostream;
using std::string;
using std::vector;

ostream &operator<<(ostream &os, vector<int> vec) {
  os << '[';
  if (vec.size() == 0) {
    os << ']';
    return os;
  }
  os << std::accumulate(std::next(vec.begin()), vec.end(),
                        std::to_string(*vec.begin()),
                        [](std::string a, const int &b) {
                          return std::move(a) + ", " + std::to_string(b);
                        });
  os << ']';
  os << endl;
  return os;
}

int operator<(vector<int> vecA, vector<int> vecB) {
  if (vecA.size() < vecB.size())
    vecA.resize(vecB.size());
  if (vecA.size() > vecB.size())
    vecB.resize(vecA.size());
  // cout << vecA << endl;
  // cout << vecB << endl;
  auto itA = vecA.begin();
  auto itB = vecB.begin();
  while (itA != vecA.end() && itB != vecB.end()) {
    if (*itA < *itB)
      return -1;
    if (*itA > *itB)
      return 1;
    ++itA;
    ++itB;
  }
  return 0;
}

class Solution {
public:
  vector<int> versionStringToDeq(const string &src) {
    vector<int> result{};
    auto split = std::views::split(src, '.');
    for (const auto &word : split) {
      auto word_view = std::string_view{word};
      int tempInt;
      std::from_chars(word_view.begin(), word_view.end(), tempInt);
      result.emplace_back(std::move(tempInt));
    }
    for (auto rIt = result.rbegin(); rIt != result.rend(); ++rIt) {
      if (*rIt == 0) {
        result.pop_back();
      } else {
        break;
      }
    }
    return result;
  }

  int compareVersion(string version1, string version2) {
    vector<int> vec1 = versionStringToDeq(version1);
    vector<int> vec2 = versionStringToDeq(version2);
    // cout << vec1 << endl;
    // cout << vec2 << endl;
    return vec1 < vec2;
  }
};
