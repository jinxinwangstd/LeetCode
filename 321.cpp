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
    bool greater(vi& nums1, vi& nums2) {
        int n = nums1.size();
        for (int i = 0; i < n; ++i)
            if (nums1[i] != nums2[i])
                return nums1[i] > nums2[i];
        return false;
    }
    vector<int> merge(vi& nums1, vi& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vi ret(n1 + n2);
        int i = 0, j = 0;
        for (int r = 0; r < n1 + n2; ++r) {
            if (i == n1)
                ret[r] = nums2[j++];
            else if (j == n2)
                ret[r] = nums1[i++];
            else
                ret[r] = nums1[i] > nums2[j] ? nums1[i++] : nums2[j++];
        }
        return ret;
    }
    vector<int> maxSingleNumber(vi& nums, int k) {
        stack<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty() && nums[i] > s.top() && s.size() + nums.size() - i > k)
                s.pop();
            if (s.size() < k)
                s.push(nums[i]);
        }
        vi ret(k);
        for (int i = k - 1; i >= 0; --i) {
            ret[i] = s.top();
            s.pop();
        }
        return ret;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vi ret;
        for (int i = max(0, k - n2); i <= n1 && i <= k; ++i) {
            vi part1 = maxSingleNumber(nums1, i);
            vi part2 = maxSingleNumber(nums2, k - i);
            vi candidate = merge(part1, part2);
            if (greater(candidate, ret))
                ret = candidate;
        }
        return ret;
    }
};
