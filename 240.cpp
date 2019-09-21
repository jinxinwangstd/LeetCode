class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < m && target > matrix[i][n - 1])
            i++;
        while (j >= 0 && target < matrix[j][0])
            j--;
        for (int row = i; row <= j; row++) {
            int l = 0, r = n - 1, mid;
            while (r - l > 1) {
                mid = l + (r - l) / 2;
                if (matrix[row][mid] < target)
                    l = mid;
                else
                    r = mid;
            }
            if (matrix[row][l] == target || matrix[row][r] == target)
                return true;
        }
        return false;
    }
};
