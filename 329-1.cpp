class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<int>> dp;
    int makeMove(vector<vector<int>>& matrix, int x, int y) {
        if (dp[x][y] > 0) 
            return dp[x][y];
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < 4; i++) {
            int adj_x = x + dx[i], adj_y = y + dy[i];
            if(adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n) 
                continue;
            if (matrix[x][y] >= matrix[adj_x][adj_y]) 
                continue;
            dp[x][y] = max(dp[x][y], 1 + makeMove(matrix, adj_x, adj_y));   
        }
        if (dp[x][y] == 0) 
            dp[x][y] = 1;
        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        dp.assign(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, makeMove(matrix, i, j));
            }
        }
        return res;    
    }
};
