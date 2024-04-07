#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int max_index = 0;
    int cur_index = 0;
    int ans = 0;
    for (int i = 0; i < nums.size() - 1; ++i) { // no need for the last one
      max_index = max(max_index, i + nums[i]);
      if (i == cur_index) {
        ans++;
        if (max_index >= nums.size() - 1) {
          break;
        }
        cur_index = max_index;
      }
    }

    return ans;
  }
};
