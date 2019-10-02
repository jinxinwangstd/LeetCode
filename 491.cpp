class Solution {
public:
    void dfs(set<vector<int>>& res, vector<int>& stack, vector<int>& nums, int pos) {
        if (stack.size() > 1)
            res.insert(vector<int>(stack.begin(), stack.end()));
        if (pos == nums.size())
            return;
        if (stack.empty() || nums[pos] >= stack.back()) {
            stack.push_back(nums[pos]);
            dfs(res, stack, nums, pos + 1);
            stack.pop_back();
        }
        dfs(res, stack, nums, pos + 1);
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> stack;
        dfs(res, stack, nums, 0);
        vector<vector<int>> ans;
        for (set<vector<int>>::iterator iter = res.begin(); iter != res.end(); iter++)
            ans.push_back(*iter);
        return ans;
    }
};
