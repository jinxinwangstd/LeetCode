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
    vi table;   // table[i] is the max sum of sequence starting at position i
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())   // corner case: the array is empty then we just return 0
            return 0;
        int n = (int)nums.size();
        table.assign(n, 0);
        table[n - 1] = nums[n - 1];
        int ret = table[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (table[i + 1] > 0)       // if the following sequence is positive, we include them
                table[i] = nums[i] + table[i + 1];
            else                        // otherwise the max sequence is the number itself
                table[i] = nums[i];
            ret = max(ret, table[i]);
        }
        return ret;
    }
};
