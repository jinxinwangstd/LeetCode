class Solution {
public:
    unordered_map<string, map<string, int>> m;
    bool dfs(vector<string>& itin, int N) {
        if (itin.size() == N)
            return true;
        string dept = itin.back();
        int n = m[dept].size();
        for (int i = 0; i < n; i++) {
            string dest = next(m[dept].begin(), i)->first;
            if (m[dept][dest] == 0)
                continue;
            m[dept][dest]--;
            itin.push_back(dest);
            if (dfs(itin, N))
                return true;
            itin.pop_back();
            m[dept][dest]++;
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int N = tickets.size() + 1;
        for (int i = 0; i < N - 1; i++)
            m[tickets[i][0]][tickets[i][1]]++;
        vector<string> res;
        res.push_back("JFK");
        dfs(res, N);
        return res;
    }
};
