class Solution {
public:
    vector<vector<vector<int>>> dp;
    int makeMove(vector<vector<int>>& books, int shelf_width, int idx, int max_height, int left_width) {
        int n = books.size();
        if (idx == n)
            return 0;
        if (dp[idx][max_height][left_width] > 0)
            return dp[idx][max_height][left_width];
        int res = INT_MAX;
        if (left_width >= books[idx][0]) {
            int height = max_height > books[idx][1] ? 0 : books[idx][1] - max_height;
            max_height = max(max_height, books[idx][1]);
            height += makeMove(books, shelf_width, idx + 1, max_height, left_width - books[idx][0]);
            res = min(res, height);
        }
        int height = books[idx][1] + makeMove(books, shelf_width, idx + 1, books[idx][1], shelf_width - books[idx][0]);
        res = min(res, height);
        return dp[idx][max_height][left_width] = res;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        dp.assign(1005, vector<vector<int>>(1005, vector<int>(1005, INT_MAX)));
        return makeMove(books, shelf_width, 0, 0, shelf_width);
    }
};
