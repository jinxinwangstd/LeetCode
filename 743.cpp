#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // build adj list of the graph
        vector<vector<pair<int, int>>> g(N + 1, vector<pair<int, int>>());
        for (int i = 0; i < times.size(); i++) {
            g[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
        // BFS
        queue<int> q;
        vector<int> dist(N + 1, -1);
        dist[K] = 0;
        q.push(K);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < g[node].size(); i++) {
                int adj_node = g[node][i].first;
                if (dist[adj_node] < 0 || dist[node] + g[node][i].second < dist[adj_node]) {
                    dist[adj_node] = dist[node] + g[node][i].second;
                    q.push(adj_node);
                }
            }
        }
        int res = INT_MIN;
        for (int i = 1; i <= N; i++) {
            if (dist[i] < 0)
                return -1;
            res = max(dist[i], res);
        }
        return res;
    }
};
