#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    // Bottom-up dynamic programming function to calculate the least number of squares sums up to "n"
    int numSquares(int n) {
        vector<int> memo;
        memo.push_back(0);
        for (int i = 1; i <= n; ++i) {
            int ans = INT_MAX;
            for (int j = 1; j * j <= i; ++j)
                ans = min(ans, 1 + memo[i - j * j]);	// recurrence relation: num(n) = 1 + num(n - first_adder)
            memo.push_back(ans);
        }
        return memo[n];
    }
};

