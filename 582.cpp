class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> adj_list;
        int n = pid.size();
        for (int i = 0; i < n; i++)
            adj_list[ppid[i]].push_back(pid[i]);
        queue<int> q;
        q.push(kill);
        vector<int> killed;
        while (!q.empty()) {
            int id = q.front();
            q.pop();
            killed.push_back(id);
            for (int i = 0; i < adj_list[id].size(); i++)
                q.push(adj_list[id][i]);
        }
        return killed;        
    }
};

/*
 * BFS in tree
 */
