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
    int coinChangeHelper(vi& coins, int amount) {
        if (amount < 0)
            return INT_MAX;
        if (table[amount] != -1)
            return table[amount];
        int ret = INT_MAX;
        for (int i = 0; i < coins.size(); ++i) {
            int rest = coinChangeHelper(coins, amount - coins[i]);
            if (rest != INT_MAX)
                ret = min(ret, 1 + rest);
        }
        return table[amount] = ret;
    }
    int coinChange(vector<int>& coins, int amount) {
        table.assign(amount + 1, -1);
        table[0] = 0;
        int ret = coinChangeHelper(coins, amount);
        return ret == INT_MAX ? -1 : ret;
    }
};
