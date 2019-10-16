/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

class Solution {
public:
    int determineBalanced(TreeNode *root) {
        if (!root)
            return 0;
        int left_depth = determineBalanced(root->left);
        int right_depth = determineBalanced(root->right);
        if (left_depth < 0 || right_depth < 0)
            return -1;
        if (abs(left_depth - right_depth) <= 1)
            return max(left_depth, right_depth) + 1;
        else
            return -1;
    }
    // This function determines whether a binary tree is height balanced
    bool isBalanced(TreeNode* root) {
        return determineBalanced(root) >= 0;
    }
};
