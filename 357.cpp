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
    int countNumbersWithUniqueDigits(int n) {
        if (!n)
            return 1;
        int ret = 0;
        /* the number of unique digit numbers for n digits is
         * A(n, 10) - A(n-1, 9)
         */
        for (int i = 1; i <= n; ++i) {
            int include = 1;
            for (int j = 0; j < i; ++j)
                include *= 10 - j;
            if (i == 1) {
                ret += include;
                continue;
            }
            int exclude = 1;
            for (int k = 0; k < i - 1; ++k)
                exclude *= 9 - k;
            ret += (include - exclude);
        }
        return ret;
    }
};
