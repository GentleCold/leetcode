#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    if (s.empty()) {
      return 0;
    }

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    while (true) {
      if (i == g.size() || j == s.size()) {
        return i;
      }

      if (g[i] <= s[j]) { // satisfy
        ++i;
        ++j;
      } else {
        ++j;
      }
    }
  }
};
