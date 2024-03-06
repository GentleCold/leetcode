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

TreeNode *buildTree(vector<int> &nums, int i, int j) {
  int k = i;
  int max = -1, max_k = i;
  while (k != j) {
    if (nums[k] > max) {
      max = nums[k];
      max_k = k;
    }
    ++k;
  }

  TreeNode *root = new TreeNode(max);
  if (max_k != i) {
    root->left = buildTree(nums, i, max_k);
  }

  if (max_k != j - 1) {
    root->right = buildTree(nums, max_k + 1, j);
  }

  return root;
}

class Solution {
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return buildTree(nums, 0, nums.size());
  }
};
