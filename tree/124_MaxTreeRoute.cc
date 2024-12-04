#include <algorithm>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  int ans;

public:
  int maxSingleChild(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int left_max = maxSingleChild(root->left);
    int right_max = maxSingleChild(root->right);
    ans = std::max(ans, left_max + right_max + root->val);
    return std::max(0, root->val + std::max(left_max, right_max));
  }
  int maxPathSum(TreeNode *root) {
    ans = -0x7fffffff;
    maxSingleChild(root);
    return ans;
  }
};
