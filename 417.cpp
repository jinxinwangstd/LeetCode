#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void bfs(vector<vector<int>>& matrix, vector<vector<int>>& dist, queue<pair<int, int>>& q) {
        int m = matrix.size(), n = matrix[0].size();
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            dist[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int adj_x = x + dx[i], adj_y = y + dy[i];
                if (adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n)
                    continue;
                if (matrix[adj_x][adj_y] >= matrix[x][y] && dist[adj_x][adj_y] == -1)
                    q.push(make_pair(adj_x, adj_y));
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return vector<vector<int>>();
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, -1));
        vector<vector<int>> atlantic(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            q.push(make_pair(i, 0));
        for (int j = 1; j < n; j++)
            q.push(make_pair(0, j));
        bfs(matrix, pacific, q);
        for (int i = 0; i < m; i++)
            q.push(make_pair(i, n -1));
        for (int j = 0; j < n - 1; j++)
            q.push(make_pair(m - 1, j));
        bfs(matrix, atlantic, q);
        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] == 1 && atlantic[i][j] == 1)
                    res.push_back({i, j});
        return res;
    }
};
