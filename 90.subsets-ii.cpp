#include <algorithm>
#include <vector>
using namespace std;

void backtrace(vector<vector<int>> &ans, vector<int> &sample,
               vector<int> &nums, int index) {
  ans.push_back(sample);

  for (int i = index; i < nums.size(); ++i) {
    if (i > index && nums[i] == nums[i - 1]) {
      continue;
    }

    sample.push_back(nums[i]);
    backtrace(ans, sample, nums, i + 1);
    sample.pop_back();
  }
}

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    // sort to avoid duplicate
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    vector<int> sample;
    backtrace(ans, sample, nums, 0);

    return ans;
  }
};
