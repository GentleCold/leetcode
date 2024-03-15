#include <algorithm>
#include <vector>
using namespace std;

void backtrace(vector<vector<int>> &ans, vector<int> &sample,
               vector<int> &candidates, int target, int index) {
  if (target == 0) {
    ans.emplace_back(sample);
    return;
  }

  for (int i = index; i < candidates.size();) {
    if (target - candidates[i] < 0) {
      break;
    }
    sample.emplace_back(candidates[i]);
    backtrace(ans, sample, candidates, target - candidates[i], i + 1);
    sample.pop_back();

    ++i;
    while (i < candidates.size() && candidates[i] == candidates[i - 1]) {
      ++i;
    }
  }
}

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> sample;

    sort(candidates.begin(), candidates.end());
    backtrace(ans, sample, candidates, target, 0);

    return ans;
  }
};
