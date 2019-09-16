#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return 0;
        if (grid[x][y] == 0 || grid[x][y] == 2)
            return 0;
        int area = 1;
        grid[x][y] = 2;
        area += dfs(grid, x + 1, y);
        area += dfs(grid, x - 1, y);
        area += dfs(grid, x, y + 1);
        area += dfs(grid, x, y - 1);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    res = max(res, dfs(grid, i, j));
        return res;
    }
};
