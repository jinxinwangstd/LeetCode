class UnionFind {
private:
    vector<int> p, size;
public:
    UnionFind(int N) {
        p = vector<int>(N, 0);
        size = vector<int>(N, 1);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int u) {
        return u == p[u] ? u : p[u] = findSet(p[u]);
    }
    int isSameSet(int u, int v) {
        return findSet(u) == findSet(v);
    }
    void unionSet(int u, int v) {
        if (!isSameSet(u, v)) {
            int x = findSet(u), y = findSet(v);
            if (size[x] > size[y]) {
                p[y] = x;
                size[x] += size[y];
            }
            else {
                p[x] = y;
                size[y] += size[x];
            }
        }
        return;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // mapping emails to unique ids
        map<string, int> ids;
        vector<string> emails;
        int n = accounts.size();
        for (int i = 0; i < n; i++) {
            int m = accounts[i].size();
            for (int j = 1; j < m; j++)
                if (!ids.count(accounts[i][j])) {
                    ids[accounts[i][j]] = emails.size();
                    emails.push_back(accounts[i][j]);
                }
        }
        // union emails of each person
        UnionFind UF(emails.size());
        for (int i = 0; i < n; i++) {
            int m = accounts[i].size();
            for (int j = 1; j < m - 1; j++)
                UF.unionSet(ids[accounts[i][j]], ids[accounts[i][j+1]]);
        }
        // mapping email ids to names
        map<int, string> set_to_name;
        for (int i = 0; i < n; i++)
            if (accounts[i].size() > 1)
                set_to_name[UF.findSet(ids[accounts[i][1]])] = accounts[i][0];
        // build email sets of each person
        vector<vector<string>> res;
        map<int, int> set_to_res;
        for (int i = 0; i < emails.size(); i++) {
            int set_id = UF.findSet(i);
            if (!set_to_res.count(set_id)) {
                set_to_res[set_id] = res.size();
                vector<string> record;
                record.push_back(emails[i]);
                res.push_back(record);
            }
            else
                res[set_to_res[set_id]].push_back(emails[i]);
        }
        // insert corresponding name to each email set
        for (int i = 0; i < n; i++) {
            if (accounts[i].size() > 1) {
                int set_id = UF.findSet(ids[accounts[i][1]]);
                int res_id = set_to_res[set_id];
                if (res[res_id][0] != set_to_name[set_id]) {
                    sort(res[res_id].begin(), res[res_id].end());
                    res[res_id].insert(res[res_id].begin(), set_to_name[set_id]);
                }
            }
            else {
                vector<string> record;
                record.push_back(accounts[i][0]);
                res.push_back(record);
            }
        }
        return res;
    }
};
