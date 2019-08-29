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
    vi cur, last;
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size(); 
        cur.resize(3);  // three columns for three situations: to buy, to sell, cooldown
        cur[0] = 0;
        cur[1] = INT_MIN;
        cur[2] = INT_MIN;
        int index = 0;
        while (index < n) {
            last = cur;
            cur[0] = max(last[0], last[2]);
            cur[1] = max(last[1], last[0] - prices[index]);
            cur[2] = last[1] + prices[index];
            index++;
        }
        return max(cur[0], max(cur[1], cur[2]));
    }
};
