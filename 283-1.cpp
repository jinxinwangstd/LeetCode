class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zero_idx = 0, non_zero_idx = 0;
        while (zero_idx < n && non_zero_idx < n) {
            if (nums[zero_idx]) {
                zero_idx++;
                if (non_zero_idx < zero_idx)
                    non_zero_idx = zero_idx;
            }
            else {
                if (!nums[non_zero_idx]) {
                    non_zero_idx++;
                    continue;
                }
                swap(nums[zero_idx], nums[non_zero_idx]);
                zero_idx++;
                non_zero_idx++;
            }
        }
        return;
    }
};

/*
 * Two pointers
 * One pointer is pointing to the first zero in the array
 * The other pointer is pointing to the first non-zero after the first zero in the array
 */
