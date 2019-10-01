class Solution {
public:
    int dfs(vector<int>& nums, int pos, int cur_sum, int S) {
        if (pos == nums.size())
            return cur_sum == S;
        int num_left = nums.size() - pos;
        if (cur_sum < S && S - cur_sum > nums[pos] * num_left)
            return 0;
        if (cur_sum > S && cur_sum - S > nums[pos] * num_left)
            return 0;
        int res = 0;
        res += dfs(nums, pos + 1, cur_sum + nums[pos], S);
        res += dfs(nums, pos + 1, cur_sum - nums[pos], S);
        return res;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(nums, 0, 0, S);
    }
};
