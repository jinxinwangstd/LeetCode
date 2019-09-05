#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int s_i = 0, t_i = 0;
        while (s_i < m && t_i < n) {
            if (s[s_i] == t[t_i])
                s_i++;
            t_i++;
        }
        return s_i == m;
    }
};
