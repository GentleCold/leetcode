#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> hash;
    int sum = 0;

    hash.insert(n);
    while (!hash.count(sum)) {
      hash.insert(n);
      sum = 0;
      while (n) {
        int single = n % 10;
        sum += single * single;
        n /= 10;
      }
      n = sum;

      if (n == 1)
        return true;
    }

    return false;
  }
};
