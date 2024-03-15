#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

array<string, 9> alpha = {"",    "abc",  "def", "ghi", "jkl",
                          "mno", "pqrs", "tuv", "wxyz"};

void trans(vector<string> &ans, string &sample, string &digits, int k) {
  if (sample.size() == digits.size()) {
    if (sample.size() != 0) {
      ans.push_back(sample);
    }
    return;
  }

  int index = digits[k] - '1';

  for (auto &c : alpha[index]) {
    sample += c;
    trans(ans, sample, digits, k + 1);
    sample.pop_back();
  }
}

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string sample = "";
    trans(ans, sample, digits, 0);
    return ans;
  }
};
