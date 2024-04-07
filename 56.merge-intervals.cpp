#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b) { return a[0] < b[0]; });

    int left = intervals[0][0], right = intervals[0][1];
    for (auto &inter : intervals) {
      if (inter[0] <= right) {
        right = max(right, inter[1]);
      } else {
        ans.push_back({left, right});
        left = inter[0];
        right = inter[1];
      }
    }

    ans.push_back({left, right});
    return ans;
  }
};
