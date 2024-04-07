#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int i = 0;
    int ans = nums[0];
    int count = 0;

    while (i < nums.size()) {
      count += nums[i];
      if (count > ans) {
        ans = count;
      }

      if (count < 0) {
        count = 0;
      }
      ++i;
    }

    return ans;
  }
};
