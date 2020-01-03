class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> record(m + n - 1, INT_MIN);
        int min = -n + 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = i - j - min;
                if (record[id] == INT_MIN)
                    record[id] = matrix[i][j];
                else if (record[id] != matrix[i][j])
                    return false;
            }
        }
        return true;
    }
};

/*
 * Diagonal ID in matrix
 */

/*
Follow up
1. What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?

2. What if the matrix is so large that you can only load up a partial row into the memory at once?

*/
