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
    int closestValue(TreeNode *root, double target) {
        // the left bound and right bound need to be far enough away from the normal range
        ll left = LLONG_MIN, right = LLONG_MAX;
        while (root) {
            if (root->val > target) {
                right = root->val;
                root = root->left;
            }
            else if (root->val < target) {
                left = root->val;
                root = root->right;
            }
            else
                return root->val;
        }
        return abs(left - target) < abs(right - target) ? left : right;
    }
};
