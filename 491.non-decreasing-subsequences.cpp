#include <unordered_set>
#include <vector>
using namespace std;

void backtrace(vector<vector<int>> &ans, vector<int> &sample, vector<int> &nums,
               int index) {
  if (sample.size() > 1) {
    ans.emplace_back(sample);
  }

  unordered_set<int> hash;

  for (int i = index; i < nums.size(); ++i) {
    if ((i > index && nums[i] == nums[i - 1]) || hash.count(nums[i])) {
      continue;
    }

    if (sample.empty() || nums[i] >= sample.back()) {
      sample.emplace_back(nums[i]);
      backtrace(ans, sample, nums, i + 1);
      sample.pop_back();
      hash.insert(nums[i]);
    }
  }
}

class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> sample;

    backtrace(ans, sample, nums, 0);
    return ans;
  }
};
