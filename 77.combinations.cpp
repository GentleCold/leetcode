#include <vector>
using namespace std;

void trans(vector<vector<int>> &ans, vector<int> &sample, int n, int k) {
  if (sample.size() == k) {
    ans.push_back(sample);
  }

  for (int i = sample.empty() ? 1 : sample.back() + 1; i <= n; ++i) {
    if (k - sample.size() > n - i + 1)
      break;
    sample.push_back(i);
    trans(ans, sample, n, k);
    sample.pop_back();
  }
}

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> sample;

    trans(ans, sample, n, k);

    return ans;
  }
};
