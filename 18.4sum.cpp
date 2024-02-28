#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0, left, right; i < n; ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      for (int j = i + 1; j < n; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;

        left = j + 1, right = n - 1;
        int half = nums[i] + nums[j];

        while (left < right) {
          int sum = nums[left] + nums[right];
          if ((long)half + sum < target) {
            while (++left < right && nums[left] == nums[left - 1])
              ;
          } else if ((long)half + sum > target) {
            while (left < --right && nums[right] == nums[right + 1])
              ;
          } else {
            ans.push_back({nums[i], nums[j], nums[left], nums[right]});
            while (++left < right && nums[left] == nums[left - 1])
              ;
            while (left < --right && nums[right] == nums[right + 1])
              ;
          }
        }
      }
    }

    return ans;
  }
};
