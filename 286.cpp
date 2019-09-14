#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty())
            return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rooms[i][j] == 0)
                    q.push(make_pair(i, j));
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int adj_x = x + dx[i], adj_y = y + dy[i];
                if (adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n)
                    continue;
                if (rooms[adj_x][adj_y] != -1 && rooms[adj_x][adj_y] > rooms[x][y] + 1) {
                    rooms[adj_x][adj_y] = rooms[x][y] + 1;
                    q.push(make_pair(adj_x, adj_y));
                }
            }
        }
        return;
    }
};
