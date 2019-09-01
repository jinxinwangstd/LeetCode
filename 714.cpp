#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector< vector<int> > dp(n + 1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN + fee;

        for (int i = 1; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1] - fee);
            dp[i][1] = max(dp[i - 1][0] - prices[i - 1], dp[i - 1][1]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};
