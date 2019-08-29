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
    vi table;   // table[i] is the number of arithmetic slices ending at position i
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = (int)A.size(), sum = 0;
        table.assign(n, 0);
        for (int i = 2; i < n; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                table[i] = table[i - 1] + 1;
            sum += table[i];
        }
        return sum;
    }
};
