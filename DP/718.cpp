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
    int findLength(vector<int>& A, vector<int>& B) {
        int m = (int)A.size(), n = (int)B.size();
        /* table[i][j] is the maximum length of common
         * subarrays starting at A[i] and B[j]
         */
        vector<vi> table(m + 1, vi(n + 1, 0));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (A[i] == B[j])
                    table[i][j] = table[i + 1][j + 1] + 1;
                else
                    table[i][j] = 0;
            }
        }
        int max_len = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                max_len = max(max_len, table[i][j]);
        return max_len;
    }
};
