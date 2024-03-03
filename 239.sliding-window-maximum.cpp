#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < k; ++i) {
      while (!dq.empty() && nums[i] > dq.back()) {
        dq.pop_back();
      }
      dq.push_back(nums[i]);
    }
    ans.push_back(dq.front());

    for (int i = 1; i <= n - k; ++i) {
      if (dq.front() == nums[i - 1]) {
        dq.pop_front();
      }

      while (!dq.empty() && nums[i + k - 1] > dq.back()) {
        dq.pop_back();
      }
      dq.push_back(nums[i + k - 1]);
      ans.push_back(dq.front());
    }
    return ans;
  }
};
