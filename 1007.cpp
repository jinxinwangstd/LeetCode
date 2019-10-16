class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int res = INT_MAX;
        int numA = 0, numB = 0;
        int target = A[0];
        for (int i = 0; i < n; i++) {
            if (A[i] != target && B[i] != target) {
                numA = INT_MAX;
                numB = INT_MAX;
                break;
            }
            else if (A[i] != target)
                numA++;
            else if (B[i] != target)
                numB++;
        }
        res = min(res, min(numA, numB));
        numA = 0;
        numB = 0;
        target = B[0];
        for (int i = 0; i < n; i++) {
            if (A[i] != target && B[i] != target) {
                numA = INT_MAX;
                numB = INT_MAX;
                break;
            }
            else if (A[i] != target)
                numA++;
            else if (B[i] != target)
                numB++;
        }
        res = min(res, min(numA, numB));
        return res != INT_MAX ? res : -1;
    }
};
