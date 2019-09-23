class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        int n = A.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] + B[0] + C[0] + D[0] > 0)  // 可行性剪枝
                break;
            int three_sum = 0;
            for (int j = 0; j < n; j++) {
                if (A[i] + B[j] + C[0] + D[0] > 0)  // 可行性剪枝
                    break;
                int target = -(A[i] + B[j]);
                int l = 0, r = n - 1, two_sum = 0;
                while (l < n && r >= 0) {
                    if (C[l] + D[r] < target) {
                        while (l + 1 < n && C[l] == C[l + 1])
                            l++;
                        l++;
                    }
                    else if (C[l] + D[r] > target) {
                        while (r - 1 >= 0 && D[r] == D[r - 1])
                            r--;
                        r--;
                    }
                    else {
                        int nc = 1, nd = 1;
                        while (l + 1 < n && C[l] == C[l + 1]) {
                            l++;
                            nc++;
                        }
                        while (r - 1 >= 0 && D[r] == D[r - 1]) {
                            r--;
                            nd++;
                        }
                        two_sum += nc * nd;
                        l++;
                        r--;
                    }
                }
                int nb = 1;
                while (j + 1 < n && B[j] == B[j + 1]) {
                    j++;
                    nb++;
                }
                three_sum += nb * two_sum;
            }
            int na = 1;
            while (i + 1 < n && A[i] == A[i + 1]) {
                i++;
                na++;
            }
            ans += na * three_sum;
        }
        return ans;
    }
};
