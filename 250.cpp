#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isUnivalSubtree(TreeNode *root) {
        // empty subtree
        if (!root)
            return true;
        // one-node subtree
        if (!root->left && !root->right) {
            count++;
            return true;
        }
        // at least one of subtrees are not unival subtrees
        bool left_ret = isUnivalSubtree(root->left), right_ret = isUnivalSubtree(root->right);
        if (!left_ret || !right_ret)
            return false;
        // only have right subtree
        if (!root->left) {
            count += root->val == root->right->val;
            return root->val == root->right->val;
        }
        // only have left subtree
        if (!root->right) {
            count += root->val == root->left->val;
            return root->val == root->left->val;
        }
        // have two subtrees
        if (root->val == root->left->val && root->val == root->right->val) {
            count++;
            return true;
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode *root) {
        count = 0;
        isUnivalSubtree(root);
        return count;
    }
private:
    int count;
};
