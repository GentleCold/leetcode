#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    // -4 -1 -1 0 1 2
    for (int k = 0, i = 1, j = nums.size(); k < nums.size() && nums[k] <= 0;
         ++k) {
      if (k > 0 && nums[k] == nums[k - 1]) {
        continue;
      }

      int target = -nums[k];
      i = k + 1;
      j = nums.size() - 1;

      while (i < j) {
        int sum = nums[i] + nums[j];
        if (sum > target) {
          while (--j > i && nums[j] == nums[j + 1]) { // remove right
          }
        } else if (sum < target) {
          while (++i < j && nums[i] == nums[i - 1]) { // remove left
          }
        } else {
          ans.push_back({nums[k], nums[i], nums[j]}); // remove both
          while (--j > i && nums[j] == nums[j + 1]) {
          }
          while (++i < j && nums[i] == nums[i - 1]) {
          }
        }
      }
    }

    return ans;
  }
};
