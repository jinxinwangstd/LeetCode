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
    bool preorder(TreeNode *root, int val) {
        if (!root)
            return true;
        if (root->val != val)
            return false;
        return preorder(root->left, val) && preorder(root->right, val);
    }
    bool isUnivalTree(TreeNode *root) {
        return preorder(root, root->val);
    }
};

/*
 * Tree traversal
 */
