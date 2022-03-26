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
    int min_diff;
    pair<int, int> dfs(TreeNode *root) {
        int min_val = root->val, max_val = root->val;
        if (root->left) {
            pair<int, int> vals = dfs(root->left);
            min_diff = min(min_diff, abs(root->val - vals.second));
            min_val = min(min_val, vals.first);
        }
        if (root->right) {
            pair<int, int> vals = dfs(root->right);
            min_diff = min(min_diff, abs(root->val - vals.first));
            max_val = max(max_val, vals.second);
        }
        return make_pair(min_val, max_val);
    }
    int minDiffInBST(TreeNode *root) {
        min_diff = INT_MAX;
        dfs(root);
        return min_diff;
    }
};
