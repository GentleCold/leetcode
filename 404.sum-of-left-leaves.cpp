// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

void trans(TreeNode *node, int &ans, bool if_left) {
  if (node) {
    if (if_left && !node->left && !node->right) {
      ans += node->val;
    }
    trans(node->left, ans, true);
    trans(node->right, ans, false);
  }
}

class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    int ans = 0;
    if (!root) {
      return 0;
    }

    trans(root->left, ans, true);
    trans(root->right, ans, false);

    return ans;
  }
};
