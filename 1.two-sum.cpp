#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    unordered_map<int, int> hash;

    for (int i = 0; i < nums.size(); ++i) {
      if (hash.count(target -  nums[i])) {
        return {i, hash[target - nums[i]]};
      }
      hash[nums[i]] = i;
    }

    return {};
  }
};
