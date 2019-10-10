// Using prefix and suffix without O(1) space complexity
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        // initially the result array stores the suffix product
        vector<int> res(n);
        res[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--)
            res[i] = res[i+1] * nums[i];
        for (int i = 0; i < n; i++) {
            res[i] = prefix * (i < n - 1 ? res[i+1] : 1);
            prefix *= nums[i];
        }
        return res;
    }
};
