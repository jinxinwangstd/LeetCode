// Binary search variation: triple search for peak
#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int l = 0, r = n - 1, a, b;
        while (r - l > 2) {
            a = l + (r - l) / 3;
            b = l + (r - l) / 3 * 2;
            if (A[a] >= A[b])
                r = b;
            else
                l = a;
        }
        return l + (r - l) / 2;
    }
};
