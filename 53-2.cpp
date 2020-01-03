class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        int dp = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            dp = max(dp + nums[i], nums[i]);
            ans = max(ans, dp);
        }
        return ans;
    }
};
