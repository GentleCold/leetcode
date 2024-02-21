#include <bits/stdc++.h>
#include <utility>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> chars;
    for (char c : s) {
      if (chars.count(c)) {
        ++chars[c];
      } else {
        chars.insert(make_pair(c, 1));
      }
    }

    for (char c : t) {
      if (chars.count(c)) {
        --chars[c];
        if (!chars[c])
          chars.erase(c);
      } else {
        return false;
      }
    }

    if (chars.empty())
      return true;
    else
      return false;
  }
};
