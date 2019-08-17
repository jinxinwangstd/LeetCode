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
    bool preorderSearch(vector<TreeNode *>& path, TreeNode *root, TreeNode *node) {
        path.push_back(root);
        if (root->val == node->val)
            return true;
        if (root->left && preorderSearch(path, root->left, node))
            return true;
        if (root->right && preorderSearch(path, root->right, node))
            return true;
        path.pop_back();
        return false;
    }
    vector<TreeNode *> findNodePath(TreeNode *root, TreeNode *node) {
        vector<TreeNode *> path;
        preorderSearch(path, root, node);
        return path;
    }
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<TreeNode *> p_path = findNodePath(root, p);
        vector<TreeNode *> q_path = findNodePath(root, q);
        for (int i = 1; i < min(p_path.size(), q_path.size()); ++i)
            if (p_path[i] != q_path[i])
                return p_path[i - 1];
        return p_path[min(p_path.size(), q_path.size()) - 1];
    }
};
