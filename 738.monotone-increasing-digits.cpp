#include <vector>
using namespace std;
class Solution {
private:
  vector<int> split(int n) {
    vector<int> ret;
    while (n) {
      ret.push_back(n % 10);
      n /= 10;
    }

    return ret;
  }

  int merge(const vector<int> &v) {
    int n = 0;
    for (auto iter = v.rbegin(); iter != v.rend(); ++iter) {
      if (*iter == 0) {
        continue;
      }
      n = n * 10 + *iter;
    }
    return n;
  }

public:
  int monotoneIncreasingDigits(int n) {
    vector<int> v = split(n);
    // 1 0 0
    // 0 0 1
    // 9 9 0
    // 0 1
    int vs = v.size() - 1;
    if (vs == 0) {
      return n;
    }
    for (int i = 0; i < vs; ++i) {
      if (v[i] < v[i + 1]) {
        --v[i + 1];
        v[i] = 9;
        int tmp = i - 1;
        while (tmp >= 0 && v[tmp] < v[tmp + 1]) {
          v[tmp] = 9;
          --tmp;
        }
      }
    }

    return merge(v);
  }
};
