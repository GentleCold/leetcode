#include <vector>
using namespace std;

class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() < 2) {
      return nums.size();
    }

    int ans = 1;
    int flag = 0;

    for (int i = 1; i < nums.size(); ++i) {
      int delta = nums[i] - nums[i - 1];
      if ((flag >= 0 && delta < 0) || (flag <= 0 && delta > 0)) {
        ++ans;
        flag = delta;
      }
    }

    return ans;
  }
};
