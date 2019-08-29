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
    int inorderSum(TreeNode *root) {
        int sum = 0;
        if (root->left) {
            if (!root->left->left && !root->left->right)
                sum += root->left->val;
            else
                sum += inorderSum(root->left);
        }
        if (root->right) {
            if (!root->right->left && !root->right->right)
                sum += 0;
            else
                sum += inorderSum(root->right);
        }
        return sum;
    }
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 0;
        return inorderSum(root);
    }
};
