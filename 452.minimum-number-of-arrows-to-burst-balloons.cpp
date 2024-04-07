#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    // 1 2 7 10
    // 6 8 12 16
    sort(points.begin(), points.end(),
         [](auto &a, auto &b) { return a[0] < b[0]; });
    int ans = 1;
    int min_index = points[0][1];

    for (auto &point : points) {
      if (point[0] > min_index) {
        ans++;
        min_index = point[1];
      }
      min_index = min(min_index, point[1]);
    }

    return ans;
  }
};
