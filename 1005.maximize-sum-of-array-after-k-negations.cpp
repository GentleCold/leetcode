#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    priority_queue<int> queue;
    int tmp = INT_MAX;
    int ans = 0;
    for (const auto &n : nums) {
      if (n < 0) {
        if (k == 0 && n < queue.top()) {
          cout << queue.top();
          ans += 2 * queue.top() - n;
          queue.pop();
          queue.push(n);
        } else if (k > 0) {
          ans -= n;
          --k;
          queue.push(n);
        } else {
          ans += n;
        }
      } else {
        ans += n;
      }
      tmp = min(tmp, abs(n));
    }

    if (k % 2 == 1) {
      ans -= 2 * tmp;
    }

    return ans;
  }
};
