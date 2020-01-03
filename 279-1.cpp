class Solution {
public:
    vector<int> dp;
    int makeMove(int n) {
        if (dp[n] != INT_MAX)
            return dp[n];
        for (int i = 1; i*i <= n; i++) {
            dp[n] = min(dp[n], 1 + makeMove(n - i*i));
        }
        return dp[n];
    }
    int numSquares(int n) {
        dp.assign(n + 1, INT_MAX);
        dp[0] = 0;
        return makeMove(n);
        
    }
};
