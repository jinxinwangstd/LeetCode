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
    vector<vi> table;
    int maxCoins(vector<int>& nums) {
        int n = (int)nums.size() + 2;
        vi new_nums(n);
        for (int i = 1; i < n - 1; ++i)
            new_nums[i] = nums[i - 1];
        new_nums[0] = new_nums[n - 1] = 1;
        vi row(n, 0);
        table.assign(n, row);
        for (int left = n - 2; left >= 0; --left) {             //
            for (int right = left + 2; right < n; ++right) {    //
                for (int i = left + 1; i < right; ++i) {        // poped every possible ballon
                    table[left][right] = max(table[left][right], 
                            new_nums[left] * new_nums[i] * new_nums[right] + table[left][i] + table[i][right]);
                }
            }
        }
        return table[0][n - 1];
    }
};
