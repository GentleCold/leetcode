#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;
    }

    int target = sum / 2;
    vector<int> dp(target + 1);

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = max(dp[j], nums[i] + dp[j - nums[i]]);
      }
    }

    return dp[target] == target;
  }
};
