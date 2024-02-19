#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int left = 0, right = 0, n = nums.size();
    int ans = 1e5 + 1;

    while (right < n || target <= 0) {
      if (target > 0) {
        target -= nums[right++];
      } else {
        ans = min(ans, right - left);
        target += nums[left++];
      }
    }

    if (ans == 1e5 + 1)
      return 0;
    else
      return ans;
  }
};
