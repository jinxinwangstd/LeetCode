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
    int oddEvenJumps(vector<int>& A) {
        int n = (int)A.size();
        vector<bool> odd_reachable(n, false);
        vector<bool> even_reachable(n, false);
        /* cause in each state, we can only jump to the right side
         * we use a map to store all right-side values and their positions
         */
        map<int, int> right_values;
        odd_reachable[n - 1] = true;
        even_reachable[n - 1] = true;
        right_values[A[n - 1]] = n - 1;

        for (int i = n - 2; i >= 0; --i) {
            int value = A[i];
            if (right_values.count(value)) {
                odd_reachable[i] = even_reachable[right_values[value]];
                even_reachable[i] = odd_reachable[right_values[value]];
            }
            else {
                map<int, int>::iterator higher = right_values.lower_bound(value);
                if (higher != right_values.end())
                    odd_reachable[i] = even_reachable[higher->second];
                if (higher != right_values.begin()) {
                    map<int, int>::iterator lower = prev(higher);
                    even_reachable[i] = odd_reachable[lower->second];
                }
            }
            /* store the right-side values
             * if duplicate values, store the left one
             */
            right_values[value] = i;
        }
        int count = 0;
        for (int i = 0; i < n; ++i)
            count += odd_reachable[i];
        return count;
    }
};
