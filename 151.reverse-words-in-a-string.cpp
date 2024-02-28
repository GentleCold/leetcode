#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    // remove blank
    int i = 0, j = 0, n = s.size();
    for (; j < n; ++j) {
      if (s[j] != ' ' || (j > 0 && s[j - 1] != ' ')) {
        s[i++] = s[j];
      }
    }
    if (s[j - 1] == ' ') // maybe i = j
      s.resize(i - 1);
    else
      s.resize(i);

    n = s.size();

    // reverse sentence
    for (i = 0, j = n - 1; i < n / 2; ++i, --j) {
      swap(s[i], s[j]);
    }

    // reverse words
    for (i = 0, j = 0; i < n; ++j, i = j) {
      while (j < n && s[j] != ' ') {
        ++j;
      };

      for (int left = i, right = j - 1; left < (right + left + 1) / 2; // use +
           ++left, --right) {
        swap(s[left], s[right]);
      }
    }
    return s;
  }
};
