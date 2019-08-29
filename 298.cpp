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
    void findLongestPath(TreeNode *root, int length) {
        longest_len = max(longest_len, length);
        if (root->left) {
            if (root->val + 1 == root->left->val)
                findLongestPath(root->left, length + 1);
            else
                findLongestPath(root->left, 1);
        }
        if (root->right) {
            if (root->val + 1 == root->right->val)
                findLongestPath(root->right, length + 1);
            else
                findLongestPath(root->right, 1);
        }
        return;
    }
    int longestConsecutive(TreeNode *root) {
        if (!root)
            return 0;
        longest_len = 0;
        findLongestPath(root, 1);
        return longest_len;
    }
private:
    int longest_len;
};
