#include <bits/stdc++.h>
using namespace std;

enum class Direct { right, left, up, down };

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));

    pair<int, int> pos(0, 0);
    auto direct = Direct::right;
    int limit = 0;

    for (int i = 1; i <= n * n; ++i) {
      ans[pos.first][pos.second] = i;

      if (direct == Direct::right) {
        pos.second += 1;
        if (pos.second == n - limit - 1)
          direct = Direct::down;
      } else if (direct == Direct::down) {
        pos.first += 1;
        if (pos.first == n - limit - 1)
          direct = Direct::left;
      } else if (direct == Direct::left) {
        pos.second -= 1;
        if (pos.second == 0 + limit) {
          direct = Direct::up;
          ++limit;
        }
      } else {
        pos.first -= 1;
        if (pos.first == 0 + limit)
          direct = Direct::right;
      }
    }

    return ans;
  }
};
