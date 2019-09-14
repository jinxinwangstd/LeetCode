#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void floodFill(vector<vector<int>>& A, int value1, int value2) {
        int m = A.size(), n = A[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (A[i][j] == value1) {
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    A[i][j] = value2;
                    while (!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int adj_x = x + dx[i], adj_y = y + dy[i];
                            if (adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n)
                                continue;
                            if (A[adj_x][adj_y] == value1) {
                                A[adj_x][adj_y] = value2;
                                q.push(make_pair(adj_x, adj_y));
                            }
                        }
                    }
                    return;
                }
            }
        return;
    }
    int bfs(vector<vector<int>>& A, vector<vector<int>>& dist, int start_x, int start_y, int target) {
        int m = A.size(), n = A[0].size();
        dist = vector<vector<int>>(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        dist[start_x][start_y] = 0;
        q.push(make_pair(start_x, start_y));
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (A[x][y] == target)
                return dist[x][y];
            for (int i = 0; i < 4; i++) {
                int adj_x = x + dx[i], adj_y = y + dy[i];
                if (adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n)
                    continue;
                if (dist[adj_x][adj_y] == -1) {
                    dist[adj_x][adj_y] = dist[x][y] + 1;
                    q.push(make_pair(adj_x, adj_y));
                }
            }
        }
        return -1;
    }
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        floodFill(A, 1, 2);
        vector<vector<int>> dist;
        int res = INT_MAX;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (A[i][j] == 1)
                    res = min(res, bfs(A, dist, i, j, 2));
        return res;
    }
};
