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
    void inorderTraversal(vector<ll>& ret, TreeNode *root) {
        if (!root)
            return;
        inorderTraversal(ret, root->left);
        ret.push_back(root->val);
        inorderTraversal(ret, root->right);
        return;
    }
    vector<int> closestKValues(TreeNode *root, double target, int k) {
        vi ret;
        vector<ll> seq;
        if (!k)
            return ret;
        // construct ordered sequence of node values
        seq.push_back(LLONG_MIN);
        inorderTraversal(seq, root);
        seq.push_back(LLONG_MAX);
        // find the neighboring positions
        int left_pos = 0, right_pos = 0;
        while (seq[left_pos + 1] < target)
            left_pos++;
        right_pos = left_pos + 1;
        // select k nearest values from two sides
        while (k) {
            double left_diff = abs(seq[left_pos] - target);
            double right_diff = abs(seq[right_pos] - target);
            ret.push_back(left_diff < right_diff ? seq[left_pos--] : seq[right_pos++]);
            k--;
        }
        return ret;
    }
};
