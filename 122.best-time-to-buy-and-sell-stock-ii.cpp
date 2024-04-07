#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    int stock = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] <= stock) {
        stock = prices[i];
      } else {
        ans += prices[i] - stock;
        stock = prices[i];
      }
    }

    return ans;
  }
};
