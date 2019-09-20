class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1, mid;
            while (r - l > 1) {
                mid = l + (r - l) / 2;
                if (matrix[i][mid] < target)
                    l = mid;
                else
                    r = mid;
            }
            if (matrix[i][l] == target || matrix[i][r] == target)
                return true;
        }
        return false;
    }
};
