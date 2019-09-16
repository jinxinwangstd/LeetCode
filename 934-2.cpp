#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(vector<vector<int>>& A, vector<vector<int>>& dist, queue<pair<int, int>>& q, int x, int y, int m, int n) {
        A[x][y] = 0;
        dist[x][y] = 0;
        q.push(make_pair(x, y));
        for (int i = 0; i < 4; i++) {
            int adj_x = x + dx[i], adj_y = y + dy[i];
            if (adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n)
                continue;
            if (A[adj_x][adj_y])
                dfs(A, dist, q, adj_x, adj_y, m, n);
        }
        return;
    }
    void bfs(vector<vector<int>>& A, vector<vector<int>>& dist, queue<pair<int, int>>& q) {
        int m = A.size(), n = A[0].size();
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
        return;
    }
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        bool break_flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (A[i][j]) {
                    dfs(A, dist, q, i, j, m, n);
                    break_flag = true;
                    break;
                }
            if (break_flag)
                break;
        }
        bfs(A, dist, q);
        int res = INT_MAX;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (A[i][j] == 1)
                    res = min(res, dist[i][j] - 1);
        return res;
    }
};
