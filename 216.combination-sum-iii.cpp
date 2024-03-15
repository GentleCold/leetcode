#include <bits/stdc++.h>
using namespace std;

void trans(vector<vector<int>> &ans, vector<int> &sample, int s, int n, int k) {
  if (n == 0 && k == 0) {
    ans.push_back(sample);
    return;
  } else if (n < 0 || k < 0) {
    return;
  }

  for (int i = s; i >= k; --i) {
    if (n - i > (i - 1) * (k - 1))
      break;

    sample.push_back(i);
    trans(ans, sample, i - 1, n - i, k - 1);
    sample.pop_back();
  }
}

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> sample;
    trans(ans, sample, 9, n, k);
    return ans;
  }
};
