#include <vector>
using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int max_index = 0;
    // 3 0 8 2 0 0 1
    for (int i = 0; i < nums.size(); ++i) {
      if (i + nums[i] > max_index) {
        max_index = i + nums[i];
        if (max_index >= nums.size() - 1) {
          return true;
        }
      } else if (i >= max_index) {
        if (max_index >= nums.size() - 1) {
          return true;
        }
        break;
      }
    }

    return false;
  }
};
