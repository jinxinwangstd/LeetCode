#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n, mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            int count = 0;
            for (int i = 0; i < n; i++)
                count += nums[i] <= mid;
            if (count <= mid)
                l = mid;
            else
                r = mid;
        }
        int count = 0;
        for (int i = 0; i < n; i++)
            count += nums[i] == l;
        if (count > 1)
            return l;
        else
            return r;
    }
};
