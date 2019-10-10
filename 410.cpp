class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = (int)nums.size();
        vector<int64_t> pre_sum(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            pre_sum[i] = (int64_t)nums[i - 1] + pre_sum[i - 1];
        // table[i][j] is the maximum sum of [1...i] split into j parts
        vector<vector<int64_t>> table(n + 1, vector<int64_t>(m + 1, INT_MAX));
        table[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 0; k < i; ++k) {
                    table[i][j] = min(table[i][j], max(table[k][j-1], pre_sum[i] - pre_sum[k]));
                }
            }
        }
        return table[n][m];
    }
};
