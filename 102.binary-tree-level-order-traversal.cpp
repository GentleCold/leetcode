#include <queue>
#include <vector>
using namespace std;

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> q;

    vector<vector<int>> ans;
    vector<int> level;

    if (root) {
      q.push(root);
      q.push(nullptr);
    }

    while (q.size() > 1) {
      TreeNode *node;

      while (true) {
        auto node = q.front();
        q.pop();

        if (node)
          level.emplace_back(node->val);
        else
          break;

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }

      q.push(nullptr);

      ans.emplace_back(level);
      level.clear();
    }

    return ans;
  }
};
