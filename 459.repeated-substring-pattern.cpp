#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    string t = s + s;
    t.erase(t.begin());
    t.erase(t.end() - 1);

    if (t.find(s) != string::npos) { // O(2n - 2 + n)
      return true;
    }
    return false;
  }
};
