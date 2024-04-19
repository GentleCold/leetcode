#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> dp(s.size() + 1, false);

    dp[0] = true;

    for (int j = 1; j <= s.size(); ++j) {
      for (int i = 0; i < wordDict.size(); ++i) {
        int size = wordDict[i].size();
        if (j - size >= 0 && dp[j] == false) {
          dp[j] = dp[j - size] && (s.substr(j - size, size) == wordDict[i]);
        }
      }
    }

    return dp[s.size()];
  }
};
