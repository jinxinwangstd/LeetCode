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
    int rangeBitwiseAnd(int m, int n) {
        ll llm = (ll)m;
        ll lln = (ll)n;
        int ret = ~0;
        for (ll i = llm; i <= lln; ++i) {
            if (ret == 0)
                break;
            ret &= i;
        }
        return ret;
    }
};
