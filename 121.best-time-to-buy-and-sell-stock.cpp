#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // first: hold on the ticket
    // second: sell the ticket
    vector<pair<int, int>> dp(prices.size());

    dp[0].first = -prices[0];
    dp[0].second = 0;
    for (int i = 1; i < prices.size(); ++i) {
      // hold yesterday or buy today
      dp[i].first = max(dp[i - 1].first, -prices[i]);
      // sell today or sell yesterday
      dp[i].second = max(dp[i - 1].first + prices[i], dp[i - 1].second);
    }
    return max(dp[prices.size() - 1].first, dp[prices.size() - 1].second);
  }
};
