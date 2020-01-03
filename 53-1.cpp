class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())   // corner case: the array is empty then we just return 0
            return 0;
        int n = nums.size();
        vector<int> dp(n, 0);   // dp[i] is the max sum of sequence ending at position i
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

/*
 * Dynamic programming.
 */
