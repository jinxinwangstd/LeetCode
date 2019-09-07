#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m = A.size(), n = A[0].size();
        int res = 0;
        for (int j = 0; j < n; j++) {
            bool check_flag = true;
            for (int i = 0; i < m - 1; i++) {
                if (A[i][j] > A[i + 1][j]) {
                    check_flag = false;
                    break;
                }
            }
            if (!check_flag)
                res++;
        }
        return res;
    }
};
