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

// UnionFind
class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool validCoord(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int num_region = n * n * 4;
        UnionFind UF(num_region);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int cell_id = (i * n + j) * 4;
                if (grid[i][j] == '\\') {
                    UF.unionSet(cell_id + 0, cell_id + 3);
                    UF.unionSet(cell_id + 1, cell_id + 2);
                }
                else if (grid[i][j] == '/') {
                    UF.unionSet(cell_id + 0, cell_id + 1);
                    UF.unionSet(cell_id + 2, cell_id + 3);
                }
                else {
                    UF.unionSet(cell_id + 0, cell_id + 1);
                    UF.unionSet(cell_id + 1, cell_id + 2);
                    UF.unionSet(cell_id + 2, cell_id + 3);
                }
                int adj_x, adj_y, adj_cell_id;
                adj_x = i + dx[0];
                adj_y = j + dy[0];
                if (validCoord(adj_x, adj_y, n)) {
                    adj_cell_id = (adj_x * n + adj_y) * 4;
                    UF.unionSet(cell_id + 3, adj_cell_id + 1);
                }
                adj_x = i + dx[1];
                adj_y = j + dy[1];
                if (validCoord(adj_x, adj_y, n)) {
                    adj_cell_id = (adj_x * n + adj_y) * 4;
                    UF.unionSet(cell_id + 1, adj_cell_id + 3);
                }
                adj_x = i + dx[2];
                adj_y = j + dy[2];
                if (validCoord(adj_x, adj_y, n)) {
                    adj_cell_id = (adj_x * n + adj_y) * 4;
                    UF.unionSet(cell_id + 2, adj_cell_id + 0);
                }
                adj_x = i + dx[3];
                adj_y = j + dy[3];
                if (validCoord(adj_x, adj_y, n)) {
                    adj_cell_id = (adj_x * n + adj_y) * 4;
                    UF.unionSet(cell_id + 0, adj_cell_id + 2);
                }
            }
        int ans = 0;
        for (int i = 0; i < num_region; i++)
            if (i == UF.findSet(i))
                ans++;
        return ans;
    }
};
