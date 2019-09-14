#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), num = n;
        queue<int> q;
        vector<int> dist(n, -1);
        // multiple connected components
        while (num) {
            // find the start of a connected components
            for (int i = 0; i < n; i++)
                if (dist[i] == -1) {
                    dist[i] = 0;
                    num--;
                    q.push(i);
                    break;
                }
            // BFS
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int i = 0; i < graph[node].size(); i++) {
                    if (dist[graph[node][i]] == -1) {
                        dist[graph[node][i]] = ~dist[node] & 1;
                        num--;
                        q.push(graph[node][i]);
                    }
                    else if (dist[graph[node][i]] == dist[node])
                        return false;
                }
            }
        }
        return true;
    }
};
