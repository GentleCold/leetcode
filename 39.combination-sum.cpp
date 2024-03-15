#include <vector>
using namespace std;

void backtrace(vector<vector<int>> &ans, vector<int> &sample,
               vector<int> &candidates, int target, int index) {
  if (target == 0) {
    ans.emplace_back(sample);
    return;
  }

  for (int i = index; i < candidates.size(); ++i) {
    if (target - candidates[i] < 0) {
      continue;
    }
    sample.emplace_back(candidates[i]);
    backtrace(ans, sample, candidates, target - candidates[i], i);
    sample.pop_back();
  }
}

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> sample;
    backtrace(ans, sample, candidates, target, 0);
    return ans;
  }
};
