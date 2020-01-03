class Solution {
public:
    vector<vector<pair<int, int>>> dp;
    pair<int, int> makeMove(vector<int>& prefix, int M, int idx) {
        int n = prefix.size();
        if (idx >= n)
            return make_pair(0, 0);
        if (dp[idx][M] != make_pair(0, 0))
            return dp[idx][M];
        int ours = 0, oppos = 0;
        for (int i = 1; i <= M * 2; i++) {
            pair<int, int> scores = makeMove(prefix, max(M, i), idx + i);
            int num = idx + i - 1 >= n ? prefix[n - 1] : prefix[idx + i - 1] - idx == 0 ? 0 : prefix[idx - 1];
            int score1 = num + scores.second, score2 = scores.first;
            if (score1 > ours) {
                ours = score1;
                oppos = score2;
            }
        }
        return dp[idx][M] = make_pair(ours, oppos);
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<pair<int, int>>(n + 1, make_pair(0, 0)));
        vector<int> prefix(n, 0);
        prefix[0] = piles[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + piles[i];
        return makeMove(prefix, 1, 0).first;
    }
};

/*
 * Dynamic programming.
 * dp[i][j] represents the maximum our score and the corresponding opponent's score when we start the game with piles [i, end) and M = j.
 */
