/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
*/

class Solution {
public:
    int moves;
    vector<int> dfs(TreeNode *root) {
        if (!root)
            return vector<int>(2, 0);
        int total_coins = root->val, total_nodes = 1;
        vector<int> left = dfs(root->left);
        moves += abs(left[0] - left[1]);
        vector<int> right = dfs(root->right);
        moves += abs(right[0] - right[1]);
        total_coins += left[0];
        total_coins += right[0];
        total_nodes += left[1];
        total_nodes += right[1];
        vector<int> res;
        res.push_back(total_coins);
        res.push_back(total_nodes);
        return res;
    }
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};
