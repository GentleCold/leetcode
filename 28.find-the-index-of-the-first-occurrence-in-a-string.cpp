#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    // abbbab
    //  abbbab
    // 000001
    // build next
    int hs = haystack.size(), ns = needle.size();
    vector<int> next;

    next.emplace_back(-1);
    next.emplace_back(0);
    for (int i = 1, j = 0; i < ns;) {
      if (j < 0 || needle[i] == needle[j]) {
        ++i;
        ++j;
        next.emplace_back(j);
      } else {
        j = next[j];
      }
    }
    cout << next.size();

    for (int i = 0, j = 0; i < hs;) {
      if (j < 0 || haystack[i] == needle[j]) {
        ++i;
        ++j;
        if (j == ns)
          return i - ns;
      } else {
        j = next[j];
      }
    }

    return -1;
  }
};
