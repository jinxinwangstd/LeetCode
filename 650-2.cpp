class Solution {
public:
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> dp;
    int makeMove(int n, int copied) {
        if (dp[n][copied] != INF)
            return dp[n][copied];
        if (n == copied) {
            for (int i = 1; i < n; i++)
                dp[n][copied] = min(dp[n][copied], 1 + makeMove(n, i));
        }
        else if (n - copied >= copied)
            dp[n][copied] = min(dp[n][copied], 1 + makeMove(n - copied, copied));
        return dp[n][copied];
    }
    int minSteps(int n) {
        if (n == 1)
            return 0;
        dp.assign(n + 1, vector<int>(n + 1, INF));
        dp[1][0] = 0;
        dp[1][1] = 1;
        int res = INT_MAX;
        for (int i = 1; i < n; i++)
            res = min(res, makeMove(n, i));
        return res;
    }
};
