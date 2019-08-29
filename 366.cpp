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
    void preorderTraversal(vi& leaves, TreeNode *root) {
        if (root->left) {
            if (!root->left->left && !root->left->right) {
                leaves.push_back(root->left->val);
                root->left = NULL;
            }
            else
                preorderTraversal(leaves, root->left);
        }
        if (root->right) {
            if (!root->right->left && !root->right->right) {
                leaves.push_back(root->right->val);
                root->right = NULL;
            }
            else
                preorderTraversal(leaves, root->right);
        }
        return;
    }
    vector< vector<int> > findLeaves(TreeNode *root) {
        vector<vi> ret;
        if (!root)
            return ret;
        while (root->left || root->right) {
            vi leaves;
            preorderTraversal(leaves, root);
            ret.push_back(leaves);
        }
        vi leaves;
        leaves.push_back(root->val);
        ret.push_back(leaves);
        return ret;
    }
};
