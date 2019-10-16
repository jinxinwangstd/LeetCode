class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool swimToEnd(vector<vector<int>>& grid, int t) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        if (grid[0][0] <= t) {
            q.push(make_pair(0, 0));
            dist[0][0] = 0;
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int adj_x = x + dx[i], adj_y = y + dy[i];
                if (adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n)
                    continue;
                if (grid[adj_x][adj_y] > t)
                    continue;
                if (dist[adj_x][adj_y] >= 0)
                    continue;
                q.push(make_pair(adj_x, adj_y));
                dist[adj_x][adj_y] = dist[x][y] + 1;
            }
        }
        return dist[m - 1][n - 1] >= 0;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int min_val = INT_MAX, max_val = INT_MIN;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                min_val = min(min_val, grid[i][j]);
                max_val = max(max_val, grid[i][j]);
            }
        int l = min_val, r = max_val, mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            if (swimToEnd(grid, mid))
                r = mid;
            else
                l = mid;
        }
        if (swimToEnd(grid, l))
            return l;
        else
            return r;
    }
};

/*
 * Binary search for result range.
 */
