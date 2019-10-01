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
    void inorderTraverse(TreeNode *root, TreeNode **cur) {
        if (!root)
            return;
        inorderTraverse(root->left, cur);
        root->left = NULL;
        TreeNode *right = root->right;
        root->right = NULL;
        (*cur)->right = root;
        *cur = &root;
        inorderTraverse(right, cur);
        return;
    }
    TreeNode* increasingBST(TreeNode *root) {
        TreeNode *anchor = new TreeNode(0), *cur = anchor;
        inorderTraverse(root, &cur);
        return anchor->right;
    }
};
