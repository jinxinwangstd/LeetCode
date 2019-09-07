#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        const int mod = 1000000007;
        vector< vector<int> > table(L + 1, vector<int>(N + 1, 0));
        table[0][0] = 1;

        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= N; ++j) {
                table[i][j] = (table[i][j] + (ll)table[i - 1][j - 1] * (N - j + 1)) % mod;
                table[i][j] = (table[i][j] + (ll)table[i - 1][j] * max(j - K, 0)) % mod;
            }
        }
        return table[L][N];
    }
};
