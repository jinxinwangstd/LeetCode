/**
 * Definition for a binary tree node.
 * struct TreeNOde {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int max_len;
    int dfs(TreeNode *root) {
        int left_len = 0, right_len = 0;
        if (root->left) {
            left_len = dfs(root->left);
            if (root->left->val != root->val)
                left_len = 0;
        }
        if (root->right) {
            right_len = dfs(root->right);
            if (root->right->val != root->val)
                right_len = 0;
        }
        max_len = max(max_len, 1 + left_len + right_len);
        return 1 + max(left_len, right_len);
    }
    int longestUnivaluePath(TreeNode *root) {
        max_len = 0;
        if (!root)
            return max_len;
        dfs(root);
        return max_len - 1;
    }
};
