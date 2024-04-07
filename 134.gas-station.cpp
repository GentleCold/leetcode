#include <vector>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    // -2 -2 -2 3 3
    // -1 -1 1
    //
    // 5 1 2 3 4
    // 4 4 1 5 1
    // 1 -3 1 -2 3
    //
    // 5 8 2 8
    // 6 5 6 6
    // -1 3 -4 2
    int sum = 0;
    int cur = 0;
    int index = 0;
    for (int i = 0; i < gas.size(); ++i) {
      sum += gas[i] - cost[i];
      cur += gas[i] - cost[i];
      if (cur < 0) { // if current is less than 0, the start index might be i+1
        cur = 0;
        index = i + 1;
      }
    }
    if (sum < 0) {
      return -1;
    }
    return index;
  }
};
