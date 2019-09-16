#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push(make_pair(i, j));
                }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int adj_x = x + dx[i], adj_y = y + dy[i];
                if (adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n)
                    continue;
                if (dist[adj_x][adj_y] > dist[x][y] + 1) {
                    dist[adj_x][adj_y] = dist[x][y] + 1;
                    q.push(make_pair(adj_x, adj_y));
                }
            }
        }
        return dist;
    }
}; 
