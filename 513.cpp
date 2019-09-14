#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

/*
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x): val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> q;
        int num = 1;
        q.push(root);
        TreeNode *left_most = NULL;
        while (!q.empty()) {
            left_most = q.front();
            int next_num = 0;
            while (num) {
                TreeNode *node = q.front();
                q.pop();
                num--;
                if (node->left) {
                    q.push(node->left);
                    next_num++;
                }
                if (node->right) {
                    q.push(node->right);
                    next_num++;
                }
            }
            num = next_num;
        }
        return left_most->val;
    }
};
