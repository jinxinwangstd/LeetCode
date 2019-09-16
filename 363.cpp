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
    int maxSumSubmatrix(vector< vector<int> >& matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = (int)matrix.size(), n = (int)matrix[0].size();
        vector<vi> pre_sum(m + 1, vi(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                pre_sum[i][j] = matrix[i - 1][j - 1] + pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1];
            }
        }
        int max_sum = INT_MIN;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int x = i + 1; x <= m; ++x) {
                    for (int y = j + 1; y <= n; ++y) {
                        int sum = pre_sum[x][y] - pre_sum[x][j] - pre_sum[i][y] + pre_sum[i][j];
                        if (sum < k)
                            max_sum = max(max_sum, sum);
                        else if (sum == k)
                            return k;
                    }
                }
            }
        }
        return max_sum;
    }
};
