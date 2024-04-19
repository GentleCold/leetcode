#include <cstdlib>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;
    vector<int> dp(target + 1);

    for (int i = 0; i < stones.size(); ++i) {
      for (int j = target; j >= stones[i]; --j) {
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }

    return abs(sum - 2 * dp[target]);
  }
};
