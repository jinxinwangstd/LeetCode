class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        unordered_map<int, vector<int>> idxes;
        for (int i = 0; i < n; i++)
            idxes[A[i]].push_back(i);
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n - 1; i++)
            dp[i][n - 1] = 2;
        for (int j = n - 2; j >= 0; j--) {
            for (int i = j - 1; i >= 0; i--) {
                int step = A[j] - A[i];
                int third = A[j] + step;
                if (!idxes.count(third)) {
                    dp[i][j] = 2;
                    continue;
                }
                if (upper_bound(idxes[third].begin(), idxes[third].end(), j) == idxes[third].end()) {
                    dp[i][j] = 2;
                    continue;
                }
                int k = *upper_bound(idxes[third].begin(), idxes[third].end(), j);
                dp[i][j] = 1 + dp[j][k];
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

/*
 * Dynamic programming.
 * dp[i][j] represents the length of longest arithmetic sequence whose first item is A[i] and the second item is A[j].
 */
