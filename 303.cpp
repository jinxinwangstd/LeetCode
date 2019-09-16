#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class NumArray {
public:
    vi pre_sum;
    NumArray(vector<int>& nums) {
        int n = (int)nums.size();
        pre_sum.resize(n);
        if (!n)
            return;
        pre_sum[0] = nums[0];
        for (int i = 1; i < n; ++i)
            pre_sum[i] = nums[i] + pre_sum[i - 1];
        return;
    }
    int sumRange(int i, int j) {
        int sum_i = 0, sum_j = 0;
        if (i >= pre_sum.size())
            sum_i = pre_sum.back();
        else if (i <= 0)
            sum_i = 0;
        else
            sum_i = pre_sum[i - 1];
        if (j >= pre_sum.size())
            sum_j = pre_sum.back();
        else if (j < 0)
            sum_j = 0;
        else
            sum_j = pre_sum[j];
        return sum_j - sum_i;
    }
};
