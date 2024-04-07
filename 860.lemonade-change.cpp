#include <vector>
using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int five = 0;
    int ten = 0;
    for (auto &n : bills) {
      if (n == 5) {
        ++five;
      } else if (n == 10) {
        ++ten;
        if (five-- == 0) {
          return false;
        }
      } else {
        if (ten > 0 && five > 0) {
          --ten;
          --five;
        } else if (five >= 3) {
          five -= 3;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
