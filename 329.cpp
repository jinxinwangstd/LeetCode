class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int x, int y) {
        if (memo[x][y])
            return memo[x][y];
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        for (int i = 0; i < 4; i++) {
            int adj_x = x + dx[i], adj_y = y + dy[i];
            if (adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n)
                continue;
            if (matrix[adj_x][adj_y] > matrix[x][y])
                res = max(res, dfs(matrix, memo, adj_x, adj_y));
        }
        return memo[x][y] = res + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!memo[i][j])
                    dfs(matrix, memo, i, j);
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res = max(res, memo[i][j]);
        return res;
    }
};
