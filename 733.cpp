class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(vector<vector<int>>& image, int x, int y, int c1, int c2) {
        int m = image.size(), n = image[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n)
            return;
        if (image[x][y] != c1)
            return;
        image[x][y] = c2;
        for (int i = 0; i < 4; i++) {
            int adj_x = x + dx[i], adj_y = y + dy[i];
            dfs(image, adj_x, adj_y, c1, c2);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int c1 = image[sr][sc];
        if (c1 != newColor)
            dfs(image, sr, sc, c1, newColor);
        return image;
    }
};
