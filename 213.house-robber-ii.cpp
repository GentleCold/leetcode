#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> dp(nums.size()); // choose first
    vector<int> dp2(nums.size());
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    dp2[1] = nums[1];

    for (int i = 2; i < dp.size() - 1; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    for (int i = 2; i < dp2.size(); ++i) {
      dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
    }

    return max(dp[nums.size() - 2], dp2.back());
  }
};

