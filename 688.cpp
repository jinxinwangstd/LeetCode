class Solution {
public:
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    vector<vector<vector<double>>> dp;
    double knightProbability(int N, int K, int r, int c) {
        dp.assign(K + 1, vector<vector<double>>(N, vector<double>(N, 0.0)));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp[0][i][j] = 1.0;
        for (int k = 1; k <= K; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int adj_x, adj_y;
                    for (int index = 0; index < 8; index++) {
                        adj_x = i + dx[index];
                        adj_y = j + dy[index];
                        if (adj_x < 0 || adj_x >= N || adj_y < 0 || adj_y >= N)
                            continue;
                        dp[k][i][j] += dp[k-1][adj_x][adj_y] / 8;
                    }
                }
            }
        }
        return dp[K][r][c];
    }
};

