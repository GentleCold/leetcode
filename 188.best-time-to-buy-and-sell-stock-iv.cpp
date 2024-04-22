#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    vector<int> dp(2 * k + 1, 0);
    for (int i = 1; i < 2 * k + 1; i += 2) {
      dp[i] = -prices[0];
    }

    for (int i = 1; i < prices.size(); ++i) {
      for (int j = 1; j < 2 * k + 1; j += 2) {
        dp[j] = max(dp[j], dp[j - 1] - prices[i]);
        dp[j + 1] = max(dp[j + 1], dp[j] + prices[i]);
      }
    }

    return dp.back();
  }
};
