#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector< vector<int> >& special, vector<int>& needs) {
        int n = price.size(), m = special.size();
        vector<int> dp(270000, INT_MAX);
        dp[0] = 0;
        // add items into price and needs until six items
        for (int i = n; i < 6; i++) {
            price.push_back(0);
            needs.push_back(0);
        }
        // add items into special until six items
        for (int i = 0; i < m; i++) {
            int cost = special[i][n];
            special[i][n] = 0;
            for (int j = n + 1; j < 7; j++)
                special[i].push_back(0);
            special[i][6] = cost;
        }
        // T represents the terminal state
        int T = 0;
        for (int i = 0; i < 6; i++)
            T |= (needs[i] << (i * 3));

        for (int S = 1; S <= T; S++) {
            // check whether the state has more items than needs
            bool check_flag = false;
            for (int i = 0; i < 6; ++i) {
                int s = (S >> (i * 3)) & 7; // s is the amount of one item
                if (s > needs[i]) {
                    check_flag = true;
                    break;
                }
            }
            if (check_flag)
                continue;
            // transit to this state by buying one item
            for (int i = 0; i < 6; ++i) {
                int s = (S >> (i * 3)) & 7;
                if (s > 0) {
                    dp[S] = min(dp[S], dp[S & (~(7 << (i * 3))) | ((s - 1) << (i * 3))] + price[i]);
                }
            }
            // transit to this state by using one special offer
            for (int i = 0; i < m; ++i) {
                check_flag = true;
                int last_state = 0;
                for (int j = 0; j < 6; ++j) {
                    int s = (S >> (j * 3)) & 7;
                    if (s < special[i][j]) {
                        check_flag = false;
                        break;
                    }
                    last_state |= ((s - special[i][j]) << (j * 3));
                }
                if (check_flag)
                    dp[S] = min(dp[S], dp[last_state] + special[i][6]);
            }
        }
        return dp[T];
    }
};
