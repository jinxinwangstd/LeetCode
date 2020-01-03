class Solution {
public:
    map<string, int> ids;
    bool isTransformed(const string& s, const string& t) {
        int num_diff = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            num_diff += s[i] != t[i];
            if (num_diff > 1)
                return false;
        }
        return true;
    }
    void bfs(vector<vector<int>>& adj_list, vector<int>& dist, vector<int>& starts) {
        queue<int> q;
        for (int start : starts) {
            q.push(start);
            dist[start] = 0;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < adj_list[u].size(); i++) {
                int v = adj_list[u][i];
                if (dist[v] == -1) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                }
            }
        }
        return;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        for (int i = 0; i < n; i++)
            ids[wordList[i]] = i;
        if (!ids.count(endWord))
            return 0;
        vector<vector<int>> adj_list(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isTransformed(wordList[i], wordList[j])) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        vector<int> starts;
        for (int i = 0; i < n; i++) {
            if (isTransformed(beginWord, wordList[i]))
                starts.push_back(i);
        }
        if (starts.empty())
            return 0;
        vector<int> dist(n, -1);
        bfs(adj_list, dist, starts);
        if (dist[ids[endWord]] == -1)
            return 0;
        return 2 + dist[ids[endWord]];
    }
};
