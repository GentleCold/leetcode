#include <bits/stdc++.h>
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

pair<int, int> trans(TreeNode *node) {
  if (!node)
    return {0, 0};

  if (!node->right && !node->left) {
    int val = node->val;
    return {1, val};
  }

  auto [height, left_val] = trans(node->left);
  auto [height_1, left_val_1] = trans(node->right);

  if (height < height_1) {
    left_val = left_val_1;
    height = height_1;
  }

  return {1 + height, left_val};
}

class Solution {
public:
  int findBottomLeftValue(TreeNode *root) {
    auto [height, left_val] = trans(root);

    return left_val;
  }
};
