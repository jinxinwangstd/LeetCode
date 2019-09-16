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
    int robHelper(TreeNode *root) {
        if (!root)
            return 0;
        if (m.count(root))
            return m[root];
        int do_amount = root->val;
        if (root->left) {
            do_amount += robHelper(root->left->left);
            do_amount += robHelper(root->left->right);
        }
        if (root->right) {
            do_amount += robHelper(root->right->left);
            do_amount += robHelper(root->right->right);
        }
        int undo_amount = robHelper(root->left) + robHelper(root->right);
        return m[root] = max(do_amount, undo_amount);
    }
    int rob(TreeNode *root) {
        m.clear();
        return robHelper(root);
    }
private:
    map<TreeNode *, int> m;
};
