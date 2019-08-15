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
    bool nodeExist(int idx, int d, TreeNode *root) {
        TreeNode *cur = root;
        while (d) {
            cur = idx & (1 << d - 1) ? cur->right : cur->left;
            d--;
        }
        return cur != NULL;
    }
    int countNodes(TreeNode *root) {
        if (!root)
            return 0;
        // calculate the depth of the tree
        int d = 0;
        TreeNode *cur = root;
        while (cur->left) {
            cur = cur->left;
            d++;
        }
        if (d == 0)
            return 1;
        // perform binary search to check how many nodes exist in the last level
        int num_upper = (int)pow(2.0, (double)d) - 1;
        int left = 0, right = (int)pow(2.0, (double)d) - 1;
        int pivot, pivot_idx;
        while (left <= right) {
            pivot = (left + right) / 2;
            pivot_idx = pivot + num_upper + 1;
            if (nodeExist(pivot_idx, d, root))
                left = pivot + 1;
            else
                right = pivot - 1;
        }
        return num_upper + left;
    }
};
