#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> ans;
  vector<int> sample;
  unordered_set<int> hash;

  vector<vector<int>> permute(vector<int> &nums) {
    backtrace(nums);
    return ans;
  }

  void backtrace(vector<int> &nums) {
    if (sample.size() == nums.size()) {
      ans.emplace_back(sample);
      return;
    }

    for (const auto &n : nums) {
      if (!hash.count(n)) {
        sample.emplace_back(n);
        hash.insert(n);

        backtrace(nums);

        hash.erase(n);
        sample.pop_back();
      }
    }
  }
};
