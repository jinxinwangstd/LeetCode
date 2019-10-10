class Solution {
public:
    int manhattanDist(vector<int>& p, vector<int>& q) {
        return abs(p[0] - q[0]) + abs(p[1] - q[1]);
    }
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> dists(m);
        vector<int> ans(n, -1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dists[i].push(make_pair(manhattanDist(bikes[i], workers[j]), j));
            }
        }
        while (n) {
            int min_worker, min_bike, min_dist = INT_MAX;
            for (int i = 0; i < m; i++) {
                if (!dists[i].empty()) {
                    while (ans[dists[i].top().second] >= 0)
                        dists[i].pop();
                    if (dists[i].top().first < min_dist) {
                        min_dist = dists[i].top().first;
                        min_worker = dists[i].top().second;
                        min_bike = i;
                    }
                }
            }
            ans[min_worker] = min_bike;
            n--;
            dists[min_bike] = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
        }
        return ans;
    }
};
