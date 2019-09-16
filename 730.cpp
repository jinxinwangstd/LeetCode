#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        const int MOD = 1000000007;
        int n = S.size();
        /* dp[i][j] means the number of different palindromic
         * subsequences (including empty subsequences) from 
         * S[i] to S[j] inclusively.
         */
        vector<vector<int>> dp(n, vector<int>(n, 1));
        /* initial states: one character contains two palindromic
         * subsequences: itself and empty subsequence
         */
        for (int i = 0; i < n; i++)
            dp[i][i] = 2;

        for (int len = 2; len <= n; len++) {
            // maintain 4 deques for 'a', 'b', 'c', and 'd'
            deque<int> chars[4];
            // i: each possible start of subsequences of length len
            for (int i = 0; i < len - 1; i++)
                chars[S[i] - 'a'].push_back(i);
            // 
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                chars[S[j] - 'a'].push_back(j);

                for (int k = 0; k < 4; k++)
                    if (chars[k].size() > 0) {
                        dp[i][j]++;
                        int l = chars[k].front();
                        int r = chars[k].back();
                        if (l < r)
                            dp[i][j] = (dp[i][j] + dp[l + 1][r - 1]) % MOD;
                    }

                chars[S[i] - 'a'].pop_front();
            }
        }
        return (dp[0][n - 1] + MOD - 1) % MOD;
    }
};
