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
        return p[u] == u ? u : p[u] = findSet(p[u]);
    }
    bool isSameSet(int u, int v) {
        return findSet(u) == findSet(v);
    }
    int findSetSize(int u) {
        return size[findSet(u)];
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
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionFind UF(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (M[i][j])
                    UF.unionSet(i, j);
        int res = 0;
        for (int i = 0; i < n; i++)
            if (i == UF.findSet(i))
                res++;
        return res;
    }
};
