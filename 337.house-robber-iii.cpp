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
  int rob(TreeNode *root) {
    vector<int> dp = rob_tree(root);
    return max(dp[0], dp[1]);
  }

  vector<int> rob_tree(TreeNode *root) {
    if (!root) {
      return {0, 0};
    }

    vector<int> left = rob_tree(root->left);
    vector<int> right = rob_tree(root->right);

    return {root->val + left[1] + right[1],
            max(left[0], left[1]) + max(right[0], right[1])};
  }
};
