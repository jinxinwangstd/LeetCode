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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int)cost.size();
        /* up is the cost starting from the up-one level,
         * up_two is the cost starting from the up-two level
         */
        int up = cost[n - 1], up_two = 0;
        int cur = 0;
        for (int i = n - 2; i >= 0; --i) {
            cur = cost[i] + min(up, up_two);
            up_two = up;
            up = cur;
        }
        return min(up, up_two);
    }
};
