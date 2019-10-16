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
    bool determineSymmetric(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        bool res = p->val == q->val;
        res = res && determineSymmetric(p->left, q->right);
        res = res && determineSymmetric(p->right, q->left);
        return res;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return determineSymmetric(root->left, root->right);
    }
};
