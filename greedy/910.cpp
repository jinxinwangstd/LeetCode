#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        sort(A.begin(), A.end());

        int res = A[n - 1] - A[0];
        for (int i = 0; i < n - 1; i++) {
            int minr = min(A[0] + K, A[i + 1] - K);
            int maxr = max(A[i] + K, A[n - 1] - K);
            res = min(res, maxr - minr);
        }
        return res;
    }
};
