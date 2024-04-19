#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;
    for (int i = 1; i <= n / 2 + 1; ++i) {
      for (int j = i * i; j <= n; ++j) {
        dp[j] = min(dp[j], dp[j - i * i] + 1);
      }
    }

    return dp[n];
  }
};
