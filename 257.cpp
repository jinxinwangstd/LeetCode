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
    void preorderTraversal(vector<TreeNode *>& path, vector<string>& paths, TreeNode *root) {
        path.push_back(root);
        if (!root->left && !root->right) {
            string ret;
            ret += to_string(path[0]->val);
            for (int i = 1; i < path.size(); ++i) {
                ret += "->";
                ret += to_string(path[i]->val);
            }
            paths.push_back(ret);
            path.pop_back();
            return;
        }
        if (root->left)
            preorderTraversal(path, paths, root->left);
        if (root->right)
            preorderTraversal(path, paths, root->right);
        path.pop_back();
        return;
    }
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ret;
        if (!root)
            return ret;
        vector<TreeNode *> path;
        preorderTraversal(path, ret, root);
        return ret;
    }
};
