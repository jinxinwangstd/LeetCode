#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> volume(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            volume[i][0] = 0;
            q.push(make_pair(i, 0));
            if (n > 1) {
                volume[i][n - 1] = 0;
                q.push(make_pair(i, n - 1));
            }
        }
        for (int j = 1; j < n - 1; j++) {
            volume[0][j] = 0;
            q.push(make_pair(0, j));
            if (m > 1) {
                volume[m - 1][j] = 0;
                q.push(make_pair(m - 1, j));
            }
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int adj_x = x + dx[i], adj_y = y + dy[i];
                if (adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n)
                    continue;
                if (volume[adj_x][adj_y] == -1 && heightMap[adj_x][adj_y] >= heightMap[x][y]) {
                    volume[adj_x][adj_y] = 0;
                    q.push(make_pair(adj_x, adj_y));
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (volume[i][j] == -1) {
                    int height = INT_MAX;
                    vector<pair<int, int>> record;
                    q.push(make_pair(i, j));
                    volume[i][j] = -2;
                    while (!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        record.push_back(make_pair(x, y));
                        for (int k = 0; k < 4; k++) {
                            int adj_x = x + dx[k], adj_y = y + dy[k];
                            if (adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n)
                                continue;
                            if (volume[adj_x][adj_y] == 0)
                                height = min(height, heightMap[adj_x][adj_y]);
                            else if (volume[adj_x][adj_y] == -1) {
                                q.push(make_pair(adj_x, adj_y));
                                volume[adj_x][adj_y] = -2;
                            }
                        }
                    }
                    for (int k = 0; k < record.size(); k++) {
                        int x = record[k].first, y = record[k].second;
                        volume[x][y] = height;
                        res += height - heightMap[x][y];
                    }
                }
        return res;
    }
};
