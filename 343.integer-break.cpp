#include <vector>
using namespace std;

class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i - 1; ++j) {
        dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
      }
    }

    return dp[n];
  }
};
