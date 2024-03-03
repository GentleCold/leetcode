class Solution {
public:
  int countNodes(TreeNode *root) {
    if (!root)
      return 0;

    int left_h = 0, right_h = 0;

    auto cur = root;
    while (cur) {
      ++left_h;
      cur = cur->left;
    }

    cur = root;
    while (cur) {
      ++right_h;
      cur = cur->right;
    }

    if (left_h == right_h) {
      return (1 << left_h) - 1;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
