#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    void dfs1(int u, int p, vector<int>& max_height, vector<vector<int>>& tree) {
        max_height[u] = 0;
        for (int i = 0; i < tree[u].size(); i++) {
            int v = tree[u][i];
            if (v != p) {
                dfs1(v, u, max_height, tree);
                max_height[u] = max(max_height[u], max_height[v] + 1);
            }
        }
        return;
    }
    void dfs2(int u, int p, vector<int>& max_height, vector<int>& parent_height, vector<vector<int>>& tree) {
        max_height[u] = max(max_height[u], parent_height[u]);
        // find the maximum height and sub-maximum height of subtrees of u
        int max1 = 0, max2 = 0;
        for (int i = 0; i < tree[u].size(); i++) {
            int v = tree[u][i];
            if (v != p) {
                if (max1 < max_height[v] + 1) {
                    max2 = max1;
                    max1 = max_height[v] + 1;
                }
                else if (max2 < max_height[v] + 1)
                    max2 = max_height[v] + 1;
            }
        }
        
        for (int i = 0; i < tree[u].size(); i++) {
            int v = tree[u][i];
            if (v != p) {
                if (max1 == max_height[v] + 1) {
                    parent_height[v] = max(parent_height[u], max2) + 1;
                    dfs2(v, u, max_height, parent_height, tree);
                }
                else {
                    parent_height[v] = max(parent_height[u], max1) + 1;
                    dfs2(v, u, max_height, parent_height, tree);
                }
            }
        }
        return;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // reconstruct graph in adjacent list form
        vector<vector<int>> tree(n, vector<int>());
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> max_height(n, 0);
        vector<int> parent_height(n, 0);
        
        dfs1(0, -1, max_height, tree);

        dfs2(0, -1, max_height, parent_height, tree);

        int min_height = INT_MAX;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (max_height[i] <= min_height) {
                if (max_height[i] < min_height)
                    res.clear();
                res.push_back(i);
                min_height = max_height[i];
            }
        }
        return res;
    }
};
