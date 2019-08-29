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
    vi amount1;     // amount1 is the table where we robbed the first house
    vi amount2;     // amount2 is the table where we didn't
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n)
            return 0;
        if (n == 1)
            return nums[0];
        amount1.resize(n + 1);
        amount2.resize(n + 1);
        amount1[0] = 0;
        amount1[1] = nums[0];
        amount2[0] = 0;
        amount2[1] = 0;
        for (int i = 2; i < n; ++i) {
            amount1[i] = max(amount1[i - 2] + nums[i - 1], amount1[i - 1]);
            amount2[i] = max(amount2[i - 2] + nums[i - 1], amount2[i - 1]);
        }
        amount1[n] = amount1[n - 1];
        amount2[n] = max(amount2[n - 1], amount2[n - 2] + nums[n - 1]);
        return max(amount1[n], amount2[n]);
    }
};
