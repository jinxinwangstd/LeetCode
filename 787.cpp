#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // reconstruct the graph
        vector<vector<pair<int, int>>> adj_list(n, vector<pair<int, int>>());
        int m = flights.size();
        for (int i = 0; i < m; i++)
            adj_list[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        // BFS
        vector<vector<int>> dist(n, vector<int>(K + 2, INT_MAX / 2));
        queue<pair<int, int>> q;
        dist[src][0] = 0;
        q.push(make_pair(src, 0));
        while (!q.empty()) {
            int node = q.front().first, k = q.front().second;
            q.pop();
            for (int i = 0; i < adj_list[node].size(); i++) {
                int adj_node = adj_list[node][i].first, cost = adj_list[node][i].second;
                if (k + 1 <= K + 1 && dist[node][k] + cost < dist[adj_node][k + 1]) {
                    dist[adj_node][k + 1] = dist[node][k] + cost;
                    q.push(make_pair(adj_node, k + 1));
                }
            }
        }
        int res = INT_MAX / 2;
        for (int i = 0; i < K + 2; i++)
            res = min(res, dist[dst][i]);
        return res == INT_MAX / 2 ? -1 : res;
    }
};
