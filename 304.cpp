#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class NumMatrix {
public:
    vector<vi> area_sum;
    NumMatrix(vector< vector<int> >& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        int m = matrix.size(), n = matrix[0].size();
        vi row(n + 1);
        area_sum.assign(m + 1, row);
        area_sum[1][1] = matrix[0][0];
        for (int j = 2; j <= n; ++j)
            area_sum[1][j] = area_sum[1][j - 1] + matrix[0][j - 1];
        for (int i = 2; i <= m; ++i) {
            area_sum[i][1] = area_sum[i - 1][1] + matrix[i - 1][0];
            for (int j = 2; j <= n; ++j)
                area_sum[i][j] = matrix[i - 1][j - 1] + area_sum[i][j - 1] + area_sum[i - 1][j] - area_sum[i - 1][j - 1];
        }
        // fill the paddle
        for (int i = 0; i <= m; ++i)
            area_sum[i][0] = 0;
        for (int j = 0; j <= n; ++j)
            area_sum[0][j] = 0;
        return;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int area_upper_left = 0, area_left = 0, area_upper = 0, area = 0;
        if (row1 <= 0)
            row1 = 0;
        else if (row1 >= area_sum.size())
            row1 = area_sum.size() - 1;
        if (col1 <= 0)
            col1 = 0;
        else if (col1 >= area_sum[0].size())
            col1 = area_sum[0].size() - 1;
        if (row2 < 0)
            row2 = 0;
        else if (row2 >= area_sum.size() - 1)
            row2 = area_sum.size() - 1;
        else
            row2++;
        if (col2 < 0)
            col2 = 0;
        else if (col2 >= area_sum[0].size() - 1)
            col2 = area_sum[0].size() - 1;
        else
            col2++;
        return area_sum[row2][col2] + area_sum[row1][col1] - area_sum[row1][col2] - area_sum[row2][col1];
    }
};
