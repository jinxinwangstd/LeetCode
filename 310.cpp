#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // reconstruct graph in adjacent list form
        vector<vector<int>> adj_list(n, vector<int>());
        int num = edges.size();
        for (int i = 0; i < num; i++) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> res;
        int min_height = INT_MAX;
        int dist[n];
        queue<int> q;
        for (int i = 0; i < n; i++) {
            memset(dist, -1, sizeof(dist));
            q.push(i);
            dist[i] = 0;
            int height = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int j = 0; j < adj_list[node].size(); j++)
                    if (dist[adj_list[node][j]] == -1) {
                        dist[adj_list[node][j]] = dist[node] + 1;
                        height = max(height, dist[adj_list[node][j]]);
                        q.push(adj_list[node][j]);
                    }
            }
            if (height <= min_height) {
                if (height < min_height)
                    res.clear();
                res.push_back(i);
                min_height = height;
            }
        }
        return res;
    }
};
