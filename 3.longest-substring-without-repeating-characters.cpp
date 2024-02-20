#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> kind;
    int first = 0, second = 0, len = 0, n = s.size();
    while (second < n) {
      if (kind.find(s[second]) == kind.end()) {
        kind.insert(s[second++]);
      } else {
        len = max(len, second - first);
        kind.erase(s[first++]);
      }
    }
    len = max(len, second - first);
    return len;
  }
};
