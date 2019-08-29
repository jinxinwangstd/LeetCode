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
    int maximalSquare(vector< vector<char> >& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vi row(n, 0);
        // table records the length of the sub_square of 1s whose right-bottom corner is (i, j)
        vector<vi> table(m, row);
        // initial values
        for (int j = 0; j < n; ++j)
            table[0][j] = matrix[0][j] == '1' ? 1 : 0;
        for (int i = 0; i < m; ++i)
            table[i][0] = matrix[i][0] == '1' ? 1 : 0;
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1')
                    table[i][j] = min(table[i - 1][j - 1], 
                            min(table[i - 1][j], table[i][j - 1])) + 1;
                else
                    table[i][j] = 0;
            }
        int max_len = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                max_len = max(max_len, table[i][j]);
        return max_len * max_len;
    }
};
