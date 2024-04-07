#include <algorithm>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    list<vector<int>> ans;
    sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
      if (a[1] == b[1]) {
        return a[0] > b[0];
      }
      return a[1] < b[1];
    });

    for (auto &p : people) {
      int front = p[1];
      auto ptr = ans.begin();
      while (front) {
        if ((*ptr)[0] >= p[0]) {
          --front;
        }
        ++ptr;
      }

      ans.insert(ptr, p);
    }

    return vector<vector<int>>(ans.begin(), ans.end());
  }
};
