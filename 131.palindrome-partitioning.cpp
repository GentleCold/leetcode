#include <string>
#include <vector>
using namespace std;

bool if_aa(string &s) {
  for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) {
      return false;
    }
  }
  return true;
}

void backtrace(vector<vector<string>> &ans, vector<string> &sample, string &s,
               int index) {
  if (index == s.size()) {
    ans.emplace_back(sample);
    return;
  }

  for (int i = 1; i < s.size() - index + 1; ++i) {
    string substring_left = s.substr(index, i);
    if (if_aa(substring_left)) {
      sample.emplace_back(substring_left);
      backtrace(ans, sample, s, index + i);
      sample.pop_back();
    }
  }
}

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> sample;

    backtrace(ans, sample, s, 0);
    return ans;
  }
};
