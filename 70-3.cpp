class Solution {
public:
    vector<int> dp;
    int climbHelper(int n) {
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] > 1)
            return dp[n];
        dp[n] = climbHelper(n - 1) + climbHelper(n - 2);
        return dp[n];
    }
    int climbStairs(int n) {
        dp.assign(n + 1, 1);
        return climbHelper(n);
    }
};

/*
 * Dynamic programming.
 * Fibonacci sequence.
 */
