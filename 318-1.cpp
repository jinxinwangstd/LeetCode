class UnionFind {
private:
    vector<int> p, size;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        size.assign(N, 1);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int u) {
        return p[u] == u ? u : p[u] = findSet(p[u]);
    }
    bool isSameSet(int u, int v) {
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
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<UnionFind> conns(26, UnionFind(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                int ch = words[i][j] - 'a';
                conns[ch].unionSet(i, n);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bool share = false;
                for (int k = 0; k < 26; k++)
                    share = share || conns[k].isSameSet(i, j);
                if (!share)
                    res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};
