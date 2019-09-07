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
    vi table;
    int breakHelper(int n) {
        if (table[n] != 0)
            return table[n];
        int ret = 0;
        for (int i = 1; i <= n / 2; ++i) {
            ret = max(ret, i * (n - i));
            ret = max(ret, i * breakHelper(n - i));
            ret = max(ret, breakHelper(i) * (n - i));
            ret = max(ret, breakHelper(i) * breakHelper(n - i));
        }
        return table[n] = ret;
    }
    int integerBreak(int n) {
        table.assign(n + 1, 0);
        table[1] = 1;
        return breakHelper(n);
    }
};
