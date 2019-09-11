#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    void bfs(vector<vector<int>>& res, vector<vector<int>>& matrix, int x, int y) {
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i > 0 && res[i][j] + 1 < res[i - 1][j]) {
                res[i - 1][j] = res[i][j] + 1;
                q.push(make_pair(i - 1, j));
            }
            if (i < m - 1 && res[i][j] + 1 < res[i + 1][j]) {
                res[i + 1][j] = res[i][j] + 1;
                q.push(make_pair(i + 1, j));
            }
            if (j > 0 && res[i][j] + 1 < res[i][j - 1]) {
                res[i][j - 1] = res[i][j] + 1;
                q.push(make_pair(i, j - 1));
            }
            if (j < n - 1 && res[i][j] + 1 < res[i][j + 1]) {
                res[i][j + 1] = res[i][j] + 1;
                q.push(make_pair(i, j + 1));
            }
        }
        return;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0)
                    res[i][j] = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (res[i][j] == 0)
                    bfs(res, matrix, i, j);
        return res;
    }
}; 
