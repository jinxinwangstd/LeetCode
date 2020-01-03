class Solution {
public:
    int getMoneyAmount(int n) {
        if (n == 1)
            return 0;
        // table[i][j] is the cost of guarantee win in [i,j]
        vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
        // bottom-up
        for (int j = 2; j <= n; ++j) {
            for (int i = j - 1; i > 0; --i) {
                int min_cost = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    int left_cost = k - 1 < i ? 0 : table[i][k - 1];
                    int right_cost = k + 1 > j ? 0 : table[k + 1][j];
                    int cost = k + max(left_cost, right_cost);
                    min_cost = min(cost, min_cost);
                }
                table[i][j] = min_cost;
            }
        }
        return table[1][n];
    }
};

/*
 * Dynamic programming
 */
