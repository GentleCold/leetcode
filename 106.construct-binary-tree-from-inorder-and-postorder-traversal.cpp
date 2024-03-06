#include <vector>
using namespace std;

TreeNode *build_tree(vector<int> &inorder, int i, int j, vector<int> &postorder,
                     int m, int n) {
  TreeNode *root = nullptr;
  if (i == j - 1) {
    root = new TreeNode(inorder[i]);
    return root;
  }

  int middle = postorder[n - 1];
  root = new TreeNode(middle);

  int a = i;
  while (a < j) {
    if (inorder[a] == middle)
      break;
    ++a;
  }

  if (i != a) {
    root->left = build_tree(inorder, i, a, postorder, m, m + a - i);
  }

  if (j - 1 != a) {
    root->right = build_tree(inorder, a + 1, j, postorder, m + a - i, n - 1);
  }

  return root;
}

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return build_tree(inorder, 0, inorder.size(), postorder, 0,
                      postorder.size());
  }
};
