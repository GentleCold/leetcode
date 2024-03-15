#include <string>
#include <vector>

using namespace std;

void backtrace(vector<string> &ans, string &sample, string &s, int index,
               int k) {
  if (k == 0) {
    if (index == s.size())
      ans.emplace_back(sample);
    return;
  }

  for (int size = 1; size < 4; ++size) {
    if (index + size > s.size())
      return;
    if (index + size + k * 3 < s.size())
      return;

    string sub = s.substr(index, size);
    int tmp = sample.size();

    if (stoi(sub) > 255 || (sub.size() > 1 && sub[0] == '0'))
      continue;

    sample += sub;
    if (index + size != s.size()) {
      sample += '.';
    }
    backtrace(ans, sample, s, index + size, k - 1);
    sample = sample.substr(0, tmp);
  }
}

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    string sample = "";

    backtrace(ans, sample, s, 0, 4);
    return ans;
  }
};
