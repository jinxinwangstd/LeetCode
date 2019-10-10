// Use prefix and suffix with O(n) space complexity
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] * nums[i];
        vector<int> suffix(n);
        suffix[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i+1] * nums[i];
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            res[i] *= i > 0 ? prefix[i-1] : 1;
            res[i] *= i < n - 1 ? suffix[i+1] : 1;
        }
        return res;
    }
};
