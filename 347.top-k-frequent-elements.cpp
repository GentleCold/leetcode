#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> count;

    auto compare = [](auto &a, auto &b) { return a.second < b.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>
        pq(compare);

    vector<int> ans;
    for (auto &num : nums) {
      ++count[num];
    }

    for (auto &[num, freq] : count) {
      pq.push({num, freq});
    }

    while (k--) {
      ans.push_back(pq.top().first);
      pq.pop();
    }
    return ans;
  }
};
