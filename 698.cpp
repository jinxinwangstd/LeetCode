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
    int target;
    vi nums_copy;
    vi buckets;
    bool assignBuckets(int index) {
        for (int i = 0; i < buckets.size(); ++i) {
            if (buckets[i] + nums_copy[index] > target)
                continue;
            buckets[i] += nums_copy[index];     // assign the elements into bucket i
            // all elements are assigned into buckets, then we reach the goal
            if (index == nums_copy.size() - 1)
                return true;
            // if all following elements are assigned properly, we reach the goal
            if (assignBuckets(index + 1))
                return true;
            else {
                buckets[i] -= nums_copy[index]; // restore the context
                if (buckets[i] == 0)            // no need to try the following empty buckets
                    return false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % k)
            return false;
        target = sum / k;
        nums_copy = vi(nums);
        buckets = vi(k, 0);
        sort(nums_copy.begin(), nums_copy.end(), greater<int>());
        return assignBuckets(0);
    }
};
