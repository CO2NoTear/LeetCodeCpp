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
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root) {
      return root;
    }
    TreeNode *inverted_left = invertTree(root->left);
    TreeNode *inverted_right = invertTree(root->right);
    root->right = inverted_left;
    root->left = inverted_right;
    return root;
  }
};
