class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> res(n);
        int cur = n - 1;
        int l = 0, r = n - 1, val;
        while (l <= r) {
            if (abs(A[l]) > abs(A[r]))
                val = A[l++];
            else
                val = A[r--];
            res[cur--] = val * val;
        }
        return res;
    }
};

/*
 * Two pointers
 */
