#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    vector<int> dp(4);

    dp[0] = -prices[0]; // first hold
    dp[1] = 0;
    dp[2] = -prices[0]; // second hold
    dp[3] = 0;

    for (int i = 1; i < prices.size(); ++i) {
      dp[0] = max(dp[0], -prices[i]);
      dp[1] = max(dp[0] + prices[i], dp[1]);
      dp[2] = max(dp[2], dp[1] - prices[i]);
      dp[3] = max(dp[2] + prices[i], dp[3]);
    }

    return dp[3];
  }
};
