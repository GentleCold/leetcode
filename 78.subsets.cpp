#include <vector>
using namespace std;

void backtrace(vector<vector<int>> &ans, vector<int> &sample, vector<int> &nums,
               int index) {
  ans.emplace_back(sample);

  for (int i = index; i < nums.size(); ++i) {
    sample.push_back(nums[i]);
    backtrace(ans, sample, nums, i + 1);
    sample.pop_back();
  }
}

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> sample;

    backtrace(ans, sample, nums, 0);
    return ans;
  }
};
