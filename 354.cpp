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
    int maxEnvelopes(vector< vector<int> >& envelopes) {
        if (envelopes.empty())
            return 0;
        int n = (int)envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vi table(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            int outside = 0;
            for (int j = i + 1; j < n; ++j) {
                if (envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1])
                    outside = max(outside, table[j]);
            }
            table[i] += outside;
        }
        int max_layer = 0;
        for (int i = 0; i < n; ++i)
            max_layer = max(max_layer, table[i]);
        return max_layer;
    }
};
