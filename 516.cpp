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
    vector<vi> table;
    int narrowDown(string& s, int left, int right) {
        if (left > right)
            return 0;
        if (table[left][right] != 0)
            return table[left][right];
        int len = 0;
        len = max(narrowDown(s, left + 1, right), narrowDown(s, left, right - 1));
        if (s[left] == s[right])
            len = max(len, 2 + narrowDown(s, left + 1, right - 1));
        return table[left][right] = len;
    }
    int longestPalindromeSubseq(string s) {
        int n = (int)s.size();
        vi row(n, 0);
        table.assign(n, row);
        for (int i = 0; i < n; ++i)
            table[i][i] = 1;
        return narrowDown(s, 0, n - 1);
    }
};
