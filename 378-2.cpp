class Solution {
public:
    int countLessOrEqual(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int total = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] <= target)
                    total++;
        return total;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1], mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            if (countLessOrEqual(matrix, mid) >= k)
                r = mid;
            else
                l = mid;
        }
        if (countLessOrEqual(matrix, l) >= k)
            return l;
        else
            return r;
    }
};
