#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n, mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            int res = guess(mid);
            if (res == 1)
                l = mid;
            else if (res == -1)
                r = mid;
            else
                return mid;
        }
        if (!guess(l))
            return l;
        else
            return r;
    }
};
