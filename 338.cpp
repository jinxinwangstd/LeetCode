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
    vector<int> countBits(int num) {
        vi table(num + 1);
        table[0] = 0;
        for (int i = 1; i <= num; ++i)
            table[i] = table[i / 2] + (i % 2);  // i and i/2 differs by the least bit
        return table; 
    }
};
