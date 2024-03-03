// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

bool is_symmetric(TreeNode *left, TreeNode *right) {
  bool flag = false;
  if (!left && !right) {
    flag = true;
  } else if (left && right) {
    if (left->val == right->val && is_symmetric(left->left, right->right) &&
        is_symmetric(left->right, right->left)) {
      flag = true;
    }
  }

  return flag;
}

class Solution {
public:
  bool isSymmetric(TreeNode *root) {

    if (root)
      return is_symmetric(root->left, root->right);

    return true;
  }
};
