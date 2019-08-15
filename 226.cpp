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
    TreeNode* invertTree(TreeNode *root) {
        if (!root)
            return NULL;
        if (!root->left && !root->right)
            return root;
        invertTree(root->left);
        invertTree(root->right);
        // swap the left subtree and the right subtree
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};
