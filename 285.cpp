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
    TreeNode* inorderSuccessor(TreeNode *root, TreeNode *p) {
        // find the path of node p
        TreeNode *cur = root;
        vector<TreeNode *> path;
        path.push_back(cur);
        while (cur->val != p->val) {
            cur = cur->val < p->val ? cur->right : cur->left;
            path.push_back(cur);
        }
        // check the node type of the target node
        if (cur->right) {
            cur = cur->right;
            while (cur->left)
                cur = cur->left;
            return cur;
        }
        else {
            for (int i = path.size() - 1; i > 0; --i) {
                if (path[i - 1]->left == path[i])
                    return path[i - 1];
            }
            return NULL;
        }
    }
};
