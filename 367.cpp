#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num, mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            if ((ll)mid * mid < num)
                l = mid;
            else
                r = mid;
        }
        if ((ll)r * r == num)
            return true;
        else
            return false;
    }
};
