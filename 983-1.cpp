class Solution {
public:
    int lens[3] = {1, 7, 30};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, INT_MAX);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                int pay_day = days[i] + lens[j];
                vector<int>::iterator iter;
                if ((iter = lower_bound(days.begin(), days.end(), pay_day)) != days.end()) {
                    dp[i] = min(dp[i], dp[iter - days.begin()] + costs[j]);
                }
                else {
                    dp[i] = min(dp[i], costs[j]);
                }
            }
        }
        return dp[0];
    }
};

/*
 * Dynamic programming.
 * dp[i] represents the minimum cost of travelling starting from days[i]
 */
