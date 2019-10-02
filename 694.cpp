class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int left, up;
    void floodFill(vector<pair<int, int>>& island, vector<vector<int>>& grid, int x, int y, int c1, int c2) {
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n)
            return;
        if (grid[x][y] != c1)
            return;
        island.push_back(make_pair(x, y));
        up = min(up, x);
        left = min(left, y);
        grid[x][y] = c2;
        for (int i = 0; i < 4; i++) {
            int adj_x = x + dx[i], adj_y = y + dy[i];
            floodFill(island, grid, adj_x, adj_y, c1, c2);
        }
        return;
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> island;
                    up = i;
                    left = j;
                    floodFill(island, grid, i, j, 1, 2);
                    for (int k = 0; k < island.size(); k++) {
                        island[k].first -= up;
                        island[k].second -= left;
                    }
                    sort(island.begin(), island.end());
                    res.insert(island);
                }
        return res.size();
    }
};
