#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = (int)nums.size();
        vector<ll> pre_sum(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            pre_sum[i] = (ll)nums[i - 1] + pre_sum[i - 1];
        // table[i][j] is the maximum sum of [1...i] split into j parts
        vector< vector<ll> > table(n + 1, vector<ll>(m + 1, INT_MAX));
        table[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 0; k < i; ++k) {
                    table[i][j] = min(table[i][j], max(table[k][j-1], pre_sum[i] - pre_sum[k]));
                }
            }
        }
        return table[n][m];
    }
};
