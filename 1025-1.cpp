class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N + 1, false);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j < i; j++) {
                if (i % j == 0)
                    dp[i] = dp[i] || (!dp[i - j]);
            }
        }
        return dp[N];
    }
};

/*
 * Dynamic programming.
 */
