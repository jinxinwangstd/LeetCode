class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
            dp[0][i] = A[0][i];
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0)
                    dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + A[i + 1][j - 1]);
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + A[i + 1][j]);
                if (j < n - 1)
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + A[i + 1][j + 1]);
            }
        }
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};

/*
 * Dynamic programming.
 * dp[i][j] represents the minimum path sum along the way falling from the virtual node above the grid to the grid element A[i][j]
 */
