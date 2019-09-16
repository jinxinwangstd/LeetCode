#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                while (i + 1 < m && nums1[i + 1] == nums1[i])
                    i++;
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                while (j + 1 < n && nums2[j + 1] == nums2[j])
                    j++;
                j++;
            }
            else {
                res.push_back(nums1[i]);
                while (i + 1 < m && nums1[i + 1] == nums1[i])
                    i++;
                i++;
                while (j + 1 < n && nums2[j + 1] == nums2[j])
                    j++;
                j++;
            }
        }
        return res;
    }
};
