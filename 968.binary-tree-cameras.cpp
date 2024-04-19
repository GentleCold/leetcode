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

//        1
//   1         2
// n   2     n   0
//   n   0
//
//        2
//   1        2
//  n  n     0
//
//        1
//     2      n
//   n    1
//     1    n
//   n   2
//     1
//
//        0
//      n   1
//         n  2
//           n  1
class Solution {
private:
  int ans = 0;
  TreeNode *realroot;

  void trans(TreeNode *root) {
    if (root == nullptr)
      return;

    trans(root->left);
    trans(root->right);

    if (root->left || root->right) { // must have a child
      if ((root->left && root->left->val == 2) ||
          (root->right && root->right->val == 2)) {
        root->val = 1;
      }

      if ((root->left && root->left->val == 0) ||
          (root->right && root->right->val == 0)) {
        root->val = 2;
        ++ans;
      }
    }

    if (root == realroot && root->val == 0) {
      ++ans;
    }
  }

public:
  int minCameraCover(TreeNode *root) {
    realroot = root;

    trans(root);
    return ans;
  }
};
