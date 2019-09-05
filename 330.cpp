#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0;
        ll cur_max = 0;
        ll cur_max_sum = 0;
        int pos = 0;
        while (cur_max_sum < n) {
            /* the condition: nums[pos] <= cur_max_sum + 1 ensures that
             * there is no hole between cur_max_sum and cur_max_sum + nums[pos]
             */
            if (pos < nums.size() && cur_max_sum + 1 >= nums[pos]) {
                cur_max_sum += nums[pos];
                cur_max = nums[pos++];
            }
            /* we cannot form cur_max_sum + 1 by current elements
             */
            else {
                cur_max = cur_max_sum + 1;
                cur_max_sum += cur_max;
                count++;
            }
        }
        return count;
    }
};
