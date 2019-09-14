#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 2) {
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
                if (grid[adj_x][adj_y] == 1 || grid[adj_x][adj_y] == 2 && dist[adj_x][adj_y] > dist[x][y] + 1) {
                    dist[adj_x][adj_y] = dist[x][y] + 1;
                    grid[adj_x][adj_y] = 2;
                    q.push(make_pair(adj_x, adj_y));
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
                else if (grid[i][j] == 2)
                    res = max(res, dist[i][j]);
            }
        return res;
    }
};
