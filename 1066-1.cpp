class Solution {
public:
    vector<vector<int>> dp;
    int calculateManhattan(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    int makeMove(vector<vector<int>>& workers, int worker_ids, vector<vector<int>>& bikes, int bike_ids) {
        if (dp[worker_ids][bike_ids] != INT_MAX)
            return dp[worker_ids][bike_ids];
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            if (worker_ids & (1 << i)) {
                for (int j = 0; j < 10; j++) {
                    if (bike_ids & (1 << j)) {
                        sum = calculateManhattan(workers[i], bikes[j]);
                        worker_ids &= ~(1 << i);
                        bike_ids &= ~(1 << j);
                        sum += makeMove(workers, worker_ids, bikes, bike_ids);
                        worker_ids |= (1 << i);
                        bike_ids |= (1 << j);
                        dp[worker_ids][bike_ids] = min(dp[worker_ids][bike_ids], sum);
                    }
                }
            }
        }
        return dp[worker_ids][bike_ids];
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        dp.assign(1024, vector<int>(1024, INT_MAX));
        for (int j = 0; j < 1024; j++)
            dp[0][j] = 0;
        for (int i = 0; i < 1024; i++)
            dp[i][0] = 0;
        int m = workers.size(), n = bikes.size();
        return makeMove(workers, (1 << m) - 1, bikes, (1 << n) - 1);
    }
};

/*
 * Dynamic programming.
 */
