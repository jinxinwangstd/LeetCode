/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode *root, int L, int R) {
        if (!root)
            return 0;
        int sum = 0;
        if (root->val >= L && root->val <= R)
            sum += root->val;
        if (root->val < R)
            sum += dfs(root->right, L, R);
        if (root->val > L)
            sum += dfs(root->left, L, R);
        return sum;
    }
    int rangeSumBST(TreeNode *root, int L, int R) {
        return dfs(root, L, R);
    }
};
