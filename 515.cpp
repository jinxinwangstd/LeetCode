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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return vector<int>();
        queue<TreeNode*> q;
        q.push(root);
        int num = 1;
        vector<int> res;
        while (!q.empty()) {
            int largest = q.front()->val;
            int next_num = 0;
            while (num) {
                TreeNode *node = q.front();
                q.pop();
                num--;
                largest = max(largest, node->val);
                if (node->left) {
                    next_num++;
                    q.push(node->left);
                }
                if (node->right) {
                    next_num++;
                    q.push(node->right);
                }
            }
            res.push_back(largest);
            num = next_num;
        }
        return res;
    }
};
