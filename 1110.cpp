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
    void deleteHelper(vector<TreeNode*>& res, TreeNode *root, vector<int>& to_delete) {
        if (!root)
            return;
        deleteHelper(res, root->left, to_delete);
        if (root->left && root->left->val == INT_MIN)
            root->left = NULL;
        deleteHelper(res, root->right, to_delete);
        if (root->right && root->right->val == INT_MIN)
            root->right = NULL;
        vector<int>::iterator iter = lower_bound(to_delete.begin(), to_delete.end(), root->val);
        if (iter != to_delete.end() && *iter == root->val) {
            root->val  = INT_MIN;
            if (root->left)
                res.push_back(root->left);
            if (root->right)
                res.push_back(root->right);
        }
        return;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        sort(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        deleteHelper(res, root, to_delete);
        if (root->val != INT_MIN)
            res.push_back(root);
        return res;      
    }
};

