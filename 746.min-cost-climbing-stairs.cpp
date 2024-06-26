#include <vector>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    if (cost.size() == 1) {
      return cost[0];
    }

    vector<int> dp(cost.size() + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i <= cost.size(); ++i) {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp.back();
  }
};
