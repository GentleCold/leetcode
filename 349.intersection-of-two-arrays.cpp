#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> hash;
    vector<int> ans;
    for (const int &a : nums1) {
      hash.insert(a);
    }

    for (const int &a : nums2) {
      if (hash.count(a)) {
        ans.push_back(a);
        hash.erase(a);
      }
    }
    return ans;
  }
};
