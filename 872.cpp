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
    void dfsTree(vector<int>& leaf_values, TreeNode *root) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            leaf_values.push_back(root->val);
            return;
        }
        dfsTree(leaf_values, root->left);
        dfsTree(leaf_values, root->right);
        return;
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> leaf1, leaf2;
        dfsTree(leaf1, root1);
        dfsTree(leaf2, root2);
        if (leaf1.size() != leaf2.size())
            return false;
        for (int i = 0; i < leaf1.size(); i++)
            if (leaf1[i] != leaf2[i])
                return false;
        return true;
    }
};
