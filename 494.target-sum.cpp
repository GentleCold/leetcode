#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // x - (sum - x) = target
    int x = (target + sum);
    if (x < 0 || x % 2 == 1) {
      return 0;
    }
    x /= 2;

    vector<int> dp(x + 1);
    dp[0] = 1; // chose nothing.
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = x; j >= nums[i]; --j) {
        dp[j] += dp[j - nums[i]];
      }
    }

    return dp[x];
  }
};
