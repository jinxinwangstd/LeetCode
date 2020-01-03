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
    TreeNode* dfs1(TreeNode* root, int x) {
        if (!root) 
            return NULL;
        if(root -> val == x)
            return root;
        TreeNode* res = NULL;
        if ((res = dfs1(root->left, x))) 
            return res;
        if((res = dfs1(root->right, x)))
            return res;
        return NULL;
        
    }
    int dfs2(TreeNode* root) {
        if(!root)
            return 0;
        int res = 1;
        res += dfs2(root->left);
        res += dfs2(root->right);
        return res;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode *target = dfs1(root,x);
        int n2 = dfs2(target->left);
        int n3 = dfs2(target->right);
        int n1 = 1 + n2 +n3;
        return(n - n1 > n1 ) || (n2 > n - n2) || (n3 > n - n3);
    }
};

/*
 * Tree, spanning tree.
 * Three best possible node for y (starting point of our spanning tree):
 * 1. x's parent node
 * 2. x's left child node
 * 3. x's right child node
 * If any of them can win, then we guarantee a win.
 */
