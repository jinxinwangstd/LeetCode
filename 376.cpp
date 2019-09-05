#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        // find the first element which is not equal to its following one
        while (i < n && i + 1 < n && nums[i] == nums[i + 1])
            i++;
        if (n - i <= 1)
            return n - i;
        /* up > 0 means that the last trend is up;
         * up < 0 means that the last trend is down
         */
        int up = nums[i + 1] > nums[i] ? 1 : -1;
        int length = 2;
        for (i = i + 2; i < n; i++) {
            if ((nums[i] - nums[i - 1]) * up < 0) {
                up = -up;
                length++;
            }
        }
        return length;
    }
};
