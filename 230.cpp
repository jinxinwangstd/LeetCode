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
    void preorderSearch(TreeNode *root, int k, int *ret) {
        if (root->left)
            preorderSearch(root->left, k);
        n++;
        if (n == k)
            *ret = root->val;
        if (root->right)
            preorderSearch(root->right, k);
        return;
    }
    int kthSmallest(TreeNode *root, int k) {
        n = 0;
        int ret;
        preorderSearch(root, k, &ret);
        return ret;
    }
private:
    int n;
};
