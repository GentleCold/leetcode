#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> ans;
  vector<int> sample;

  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<bool> used(nums.size(), false);
    backtrace(nums, used);
    return ans;
  }

  void backtrace(vector<int> &nums, vector<bool> &used) {
    if (sample.size() == nums.size()) {
      ans.emplace_back(sample);
      return;
    }

    unordered_set<int> hash;
    for (int i = 0 ; i< nums.size(); ++i) {
      auto n = nums[i];
      if (!hash.count(n) && !used[i]) {
        sample.emplace_back(n);
        used[i] = true;

        backtrace(nums, used);

        used[i] = false;
        sample.pop_back();
        hash.insert(n);
      }
    }
  }
};
