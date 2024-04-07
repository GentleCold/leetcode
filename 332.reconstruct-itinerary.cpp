#include <bits/stdc++.h>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
  unordered_map<string, map<string, int>> journel_;
  uint32_t size_ = 0;
  bool backtrace(vector<string> &result, const string &begin) {
    if (result.size() == size_) {
      return true;
    }

    for (auto &end : journel_[begin]) {
      if (end.second > 0) {
        --end.second;
        result.emplace_back(end.first);
        if (backtrace(result, end.first)) {
          return true;
        }
        result.pop_back();
        ++end.second;
      }
    }

    return false;
  }

public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    vector<string> result;

    for (auto &ticket : tickets) {
      ++journel_[ticket[0]][ticket[1]];
    }
    size_ = tickets.size() + 1;

    result.emplace_back("JFK");
    backtrace(result, "JFK");

    return result;
  }
};
