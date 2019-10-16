class Solution {
public:
    // Use two pointers to counts
    int countLessOrEqual(vector<int>& nums, int dist) {
        int n = nums.size();
        int total = 0;
        for (int i = 1, j = 0; i < n; i++) {
            while (j < i && nums[i] - nums[j] > dist)
                j++;
            total += (i - j);
        }
        return total;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.back() - nums[0], mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            if (countLessOrEqual(nums, mid) >= k)
                r = mid;
            else
                l = mid;
        }
        if (countLessOrEqual(nums, l) >= k)
            return l;
        else
            return r;
    }
};
