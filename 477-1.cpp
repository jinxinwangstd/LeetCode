class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int num_ones = 0, num_zeros = 0;
            for (int j = 0; j < n; j++) {
                num_ones += nums[j] & 1 ? 1 : 0;
                num_zeros += nums[j] & 1 ? 0 : 1;
                nums[j] >>= 1;
            }
            res += num_ones * num_zeros;
        }
        return res;
    }
};
