#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<int> ans;
    int hash[27] = {0};
    for (int pos = 0; pos < s.size(); ++pos) {
      hash[s[pos] - 'a'] = max(hash[s[pos] - 'a'], pos);
    }

    int far = 0;
    int len = 1;
    for (int pos = 0; pos < s.size(); ++pos, ++len) {
      far = max(far, hash[s[pos] - 'a']);
      if (pos == far) {
        ans.push_back(len);
        far = 0;
        len = 0;
      }
    }

    return ans;
  }
};
