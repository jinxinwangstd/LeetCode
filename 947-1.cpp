class UnionFind {
private:
    vector<int> p, size;
    int num;
public:
    UnionFind(int N) {
        num = N;
        p.assign(N, 1);
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
            num--;
        }
    }
    int getNumSets() {
        return num;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> rows, cols;
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }
        UnionFind UF(n);
        for (auto iter = rows.begin(); iter != rows.end(); iter++) {
            for (int i = 1; i < iter->second.size(); i++)
                UF.unionSet(iter->second[i], iter->second[i - 1]);
        }
        for (auto iter = cols.begin(); iter != cols.end(); iter++) {
            for (int i = 1; i < iter->second.size(); i++)
                UF.unionSet(iter->second[i], iter->second[i - 1]);
        }
        return n - UF.getNumSets();
    }
};

/*
 * UnionFind
 * We consider all stones as nodes, and stones which have the same row or column as connected. Then all the stones would form many connected components.
 * We can prove that for each connected component, there must be at least one sequence of moves that would cut down the size of component into 1.
 * Therefore, the least number of stones after removing would be the number of connected components, and the maximum number of moves would be the difference.
 * We use the UnionFind Set to track the connected components.
 */
