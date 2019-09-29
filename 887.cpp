class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        for (int i = 1; i <= N; i++)
            dp[i][1] = i;
        for (int j = 1; j <= K; j++)
            dp[1][j] = 1;
        for (int j = 2; j <= K; j++)
            for (int i = 2; i <= N; i++) {
                int l = 1, r = i, a, b;
                while (r - l > 2) {
                    a = l + (r - l) / 3;
                    b = l + (r - l) / 3 * 2;
                    int a_num = 1 + max(dp[a - l][j - 1], dp[r - a][j]);
                    int b_num = 1 + max(dp[b - l][j - 1], dp[r - b][j]);
                    if (a_num > b_num)
                        r = b;
                    else
                        l = a;
                }
                dp[i][j] = INT_MAX;
                for (int mid = l; mid <= r; mid++)
                    dp[i][j] = min(dp[i][j], 1 + max(dp[mid - l][j - 1], dp[r - mid][j]));
            }
        return dp[N][K];
    }
};
