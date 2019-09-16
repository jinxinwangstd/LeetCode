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
    vi ways;
    int numWays(int n, int k) {
        if (!n)
            return 0;
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;
        ways.resize(n + 1);
        ways[0] = 0;
        ways[1] = k;
        ways[2] = k * k;
        for (int i = 3; i <= n; ++i) {
            /* if the current post is different from the last,
             * the number of post to paint is ways[i - 1] * (k - 1).
             * if the current post is same as the last,
             * the number of ways to paint is the number of painting ways
             * for the last different from the last second, which is
             * ways[i - 2] * (k - 1)
             */
            ways[i] = ways[i - 1] * (k - 1) + ways[i - 2] * (k - 1);
        return ways[n];
    }
};
