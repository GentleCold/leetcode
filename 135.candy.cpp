#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    vector<int> ans = {1};
    int last_index = 0;
    //     i
    // 1 2 3 1 0
    // 1 2 3 2 1
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) {
        ans.push_back(ans[i - 1] + 1);
        last_index = i;
      } else {
        ans.push_back(1);
        if (ratings[i] == ratings[i - 1]) {
          last_index = i;
        } else if (ans[i - 1] == 1) {
          int tmp = i - 1;
          while (true) {
            if (ratings[tmp] > ratings[tmp + 1] && ans[tmp] == ans[tmp + 1]) {
              ++ans[tmp];
            }
            if (tmp == last_index) {
              break;
            }
            --tmp;
          }
        }
      }
    }

    return accumulate(ans.begin(), ans.end(), 0);
  }
};
