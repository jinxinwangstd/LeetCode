#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        const int m = 1100;     // max jump distance
        vector< vector<bool> > dp(n, vector<bool>(m, false));
        dp[0][1] = true;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int step = stones[i] - stones[j];
                if (step + 1< m) {
                    dp[i][step + 1] = dp[i][step + 1] || dp[j][step];
                    dp[i][step] = dp[i][step] || dp[j][step];
                    dp[i][step - 1] = dp[i][step - 1] || dp[j][step];
                }
            }
        }
        
        bool res = false;
        for (int i = 0; i < m; ++i)
            res = res || dp[n - 1][i];
        return res;
    }
};
