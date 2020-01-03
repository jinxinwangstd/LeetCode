class Solution {
public:
    vector<vector<int>> dp;
    int makeMove(vector<int>& prefix, int idx, int K) {
        int n = prefix.size();
        if (n - idx <= K)
            return -1;
        if (idx == n)
            return INT_MAX;
        if (K < 0)
            return -1;
        if (dp[idx][K] > 0)
            return dp[idx][K];
        for (int i = idx; i < n - K; i++) {
            int cur = prefix[i] - (idx ? prefix[idx - 1] : 0);
            int follow = makeMove(prefix, i + 1, K - 1);
            dp[idx][K] = max(dp[idx][K], min(cur, follow));
        }
        return dp[idx][K];
    }
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int n = sweetness.size();
        dp.assign(n, vector<int>(K + 1, 0));
        vector<int> prefix(n, 0);
        prefix[0] = sweetness[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + sweetness[i];
        return makeMove(prefix, 0, K);
    }
};

/*
 * DP but TLE
 */
