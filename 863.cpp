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
    void preorderTraversal(vector<vector<int>>& adj_list, TreeNode *root) {
        if (!root)
            return;
        if (root->left) {
            adj_list[root->val].push_back(root->left->val);
            adj_list[root->left->val].push_back(root->val);
        }
        if (root->right) {
            adj_list[root->val].push_back(root->right->val);
            adj_list[root->right->val].push_back(root->val);
        }
        preorderTraversal(adj_list, root->left);
        preorderTraversal(adj_list, root->right);
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        const int N = 505;
        // reconstruct graph from a tree
        vector<vector<int>> adj_list(N, vector<int>());
        preorderTraversal(adj_list, root);
        // BFS
        vector<int> dist(N, -1);
        dist[target->val] = 0;
        queue<int> q;
        q.push(target->val);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < adj_list[node].size(); i++)
                if (dist[adj_list[node][i]] == -1) {
                    dist[adj_list[node][i]] = dist[node] + 1;
                    q.push(adj_list[node][i]);
                }
        }
        vector<int> res;
        for (int i = 0; i < N; i++)
            if (dist[i] == K)
                res.push_back(i);
        return res;
    }
};
