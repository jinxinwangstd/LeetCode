class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < n && sorted[l] == nums[l])
            l++;
        while (r >= 0 && sorted[r] == nums[r])
            r--;
        return r > l ? r - l + 1 : 0;
    }
};

/*
 * Two pointers
 */
