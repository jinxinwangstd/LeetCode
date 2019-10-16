class Solution {
public:
    int superEggDrop(int K, int N) {
        // dp[i][j] means that with i eggs and j maximum floors, the minimum number of moves
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= N; i++)
            dp[1][i] = i;
        for (int i = 2; i <= K; i++) {
            int s = 1;
            for (int j = 1; j <= N; j++) {
                dp[i][j] = dp[i - 1][j];
                while (s < j && dp[i - 1][s - 1] < dp[i][j - s - 1])
                    s++;
                dp[i][j] = min(dp[i][j], max(dp[i - 1][s - 1], dp[i][j - s]) + 1);
                if (s < j) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][s], dp[i][j - s - 1]) + 1);
                }
            }
        }
        return dp[K][N];
    }
};

/*
 * The recurrence relation is dp[i][j] = min(max(dp[i-1][s-1], dp[i][j-s])) + 1 where s is the number of floor to throw the egg next time and ranges from 1 to j.
 * Notice that dp[i-1][s-1] is increasing with s monotonically;
 * and dp[i][j-s] is decreasing with s monotonically.
