#include <vector>
using namespace std;

class Solution {
public:
  int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 3; i <= n; ++i) {
      // total i-1 node
      for (int j = 0; j < i; ++j) {
        dp[i] += dp[j] * dp[i - 1 - j];
      }
    }

    return dp[n];
  }
};
