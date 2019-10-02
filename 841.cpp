class Solution {
public:
    const int WHITE = 0;
    const int GRAY = 1;
    const int BLACK = 2;
    int N;
    void dfs(vector<vector<int>>& rooms, vector<int>& colors, int u) {
        colors[u] = GRAY;
        N--;
        for (int i = 0; i < rooms[u].size(); i++) {
            int v = rooms[u][i];
            if (colors[v] == WHITE)
                dfs(rooms, colors, v);
        }
        colors[u] = BLACK;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        N = rooms.size();
        vector<int> colors(N, WHITE);
        dfs(rooms, colors, 0);
        return N == 0;
    }
};
