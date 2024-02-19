#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> ans;
    int left = 0, n = nums.size();

    while (left < n && nums[left] < 0) {
      ++left;
    }

    int right = left;
    --left;
    while (left >= 0 && right < n) {
      if (nums[right] < -nums[left]) {
        ans.push_back(nums[right] * nums[right]);
        ++right;
      } else {
        ans.push_back(nums[left] * nums[left]);
        --left;
      }
    }

    while (left >= 0) {
      ans.push_back(nums[left] * nums[left]);
      --left;
    }

    while (right < n) {
      ans.push_back(nums[right] * nums[right]);
      ++right;
    }

    return ans;
  }
};
