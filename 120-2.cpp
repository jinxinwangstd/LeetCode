class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int row = 0;
        vector<int> cur(n, INT_MAX), next(n, INT_MAX);
        cur[0] = triangle[0][0];
        while (row < n - 1) {
            next.assign(n, INT_MAX);
            for (int i = 0; i <= row; i++) {
                next[i] = min(next[i], cur[i] + triangle[row + 1][i]);
                next[i + 1] = min(next[i + 1], cur[i] + triangle[row + 1][i + 1]);
            }
            cur = next;
            row++;
        }
        return *min_element(cur.begin(), cur.end());
    }
};

/*
 * Dynamic programming
 */
