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
    bool isSameTree(TreeNode *s, TreeNode *t) {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        if (s->val != t->val)
            return false;
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
    /*
     * Notice that the tree may contain duplicate values.
     */
    void dfs(vector<TreeNode*>& roots, TreeNode *root, int target) {
        if (!root)
            return;
        if (root->val == target)
            roots.push_back(root);
        dfs(roots, root->left, target);
        dfs(roots, root->right, target);
        return;
    }
    bool isSubtree(TreeNode *s, TreeNode *t) {
        vector<TreeNode*> bases;
        dfs(bases, s, t->val);
        bool res = false;
        for (TreeNode *base : bases)
            res = res || isSameTree(base, t);
        return res;
    }
};

/*
 * Tree
 */
