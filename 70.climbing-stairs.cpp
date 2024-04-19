#include <vector>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 2;

    // 1 2 3 5
    for (int i = 2; i < n; ++i) {
      dp[i] = dp[i - 2] + dp[i - 1];
    }

    return dp[n - 1];
  }
};
