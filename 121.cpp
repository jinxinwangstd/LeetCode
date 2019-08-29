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
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, max_profit = 0;
        int n = (int)prices.size();
        for (int i = 0; i < n; ++i) {
            if (prices[i] < min_price)  // find valley
                min_price = prices[i];
            else                        // find peak
                max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};
