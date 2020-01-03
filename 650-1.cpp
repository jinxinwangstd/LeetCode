class Solution {
public:
    int MAX_N = 1005;
    int minSteps(int n) {
        vector<vector<int>> dp(MAX_N, vector<int>(MAX_N, 0x3f3f3f3f));
        dp[1][0] = 0;
        dp[1][1] = 1;
        for (int i = 1; i <= 1000; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][i] = min(dp[i][i], dp[i][j] + 1);
                if (i + j < MAX_N)
                    dp[i + j][j] = min(dp[i + j][j], dp[i][j] + 1);
            }
        }
        return *min_element(dp[n].begin(), dp[n].end()); 
    }
};
