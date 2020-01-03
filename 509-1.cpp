class Solution {
public:
    vector<int> dp;
    int fibHelper(int N) {
        if (N == 0)
            return 0;
        if (N == 1 || N == 2)
            return 1;
        if (dp[N] > 0)
            return dp[N];
        dp[N] = fibHelper(N - 1) + fibHelper(N - 2);
        return dp[N];
    }
    int fib(int N) {
        dp.assign(N + 1, 0);
        return fibHelper(N);
    }
};

/*
 * Dynamic programming.
 */
