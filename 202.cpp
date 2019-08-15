#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);
        for(;;) {
            int next_n = 0;
            while (n) {
                next_n += (n % 10) * (n % 10);
                n /= 10;
            }
            if (next_n == 1)
                return true;
            if (s.count(next_n))
                return false;
            n = next_n;
            s.insert(n);
        }
    }
};
