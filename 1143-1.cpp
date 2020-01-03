class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m - 1][n - 1] = text1[m - 1] == text2[n - 1];
        for (int k = m + n - 3; k >= 0; k--) {
            for (int i = m - 1; i >= 0; i--) {
                int j = k - i;
                if (j < 0 || j >= n)
                    continue;
                dp[i][j] = max(dp[i][j], dp[i + 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j + 1]);
                if (text1[i] == text2[j])
                    dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};

/*
 * Dynamic programming.
 * dp[i][j] represents the length of longest common subsequence of text1.substr(i) and text2.substr(j);
 */
