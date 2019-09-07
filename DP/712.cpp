#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    // find the maximum ASCII value of common sequence in two strings
    int maximumCommonSeq(const string& s1, const string& s2) {
        int m = s1.size(), n = s2.size();
        vector< vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                if (s1[i] == s2[j])
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + (int)s1[i] * 2);
            }
        }
        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
        int sum = 0;
        for (char c : s1)
            sum += (int)c;
        for (char c : s2)
            sum += (int)c;
        return sum - maximumCommonSeq(s1, s2);
    }
};
