#include <string>
#include <vector>
using namespace std;

void transform(TreeNode *root, string path, vector<string> &ans) {
  path += "->";
  path += to_string(root->val);

  if (root->left) {
    transform(root->left, path, ans);
  }
  if (root->right) {
    transform(root->right, path, ans);
  }

  if (!root->left && !root->right) {
    ans.push_back(path);
  }
}

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    if (!root)
      return {};

    vector<string> ans;
    string path = to_string(root->val);

    if (root->left)
      transform(root->left, path, ans);
    if (root->right)
      transform(root->right, path, ans);

    if (!root->left && !root->right) {
      ans.push_back(path);
    }
    return ans;
  }
};
