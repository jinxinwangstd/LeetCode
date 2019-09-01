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
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vi res(k, INT_MIN);
        for (int i = max(0, k - n2); i <= min(k, n1); ++i) {
            int j = k - i;
            vi N1 = maxArray(nums1, i);
            vi N2 = maxArray(nums2, j);
            vi temp = merge(N1, N2);
            if (res < temp)
                res = temp;
        }
        return res;
    }
    vector<int> merge(vi& nums1, vi& nums2) {
        vi res;
        while (nums1.size() && nums2.size()) {
            if (nums1 > nums2) {
                res.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
            else {
                res.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
        }
        while (nums1.size()) {
            res.push_back(nums1[0]);
            nums1.erase(nums1.begin());
        }
        while (nums2.size()) {
            res.push_back(nums2[0]);
            nums2.erase(nums2.begin());
        }
        return res;
    }
    vector<int> maxArray(vi& nums, int k) {
        int n = nums.size();
        vi res(k);
        for (int i = 0, j = 0; i < n; ++i) {
            while (j && res[j - 1] < nums[i] && n - i + j > k)
                j--;
            if (j < k)
                res[j++] = nums[i];
        }
        return res;
    }
};
