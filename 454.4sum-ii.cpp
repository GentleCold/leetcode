#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    int count = 0;
    int s1 = nums1.size(), s2 = nums2.size(), s3 = nums3.size(),
        s4 = nums4.size();
    unordered_map<int, int> hash;

    for (int i = 0; i < s1; ++i) {
      for (int j = 0; j < s2; ++j) {
        ++hash[nums1[i] + nums2[j]];
      }
    }

    for (int i = 0; i < s1; ++i) {
      for (int j = 0; j < s2; ++j) {
        int target = -nums3[i] - nums4[j];
        if (hash.count(target)) {
          count += hash[target];
        }
      }
    }

    return count;
  }
};
