class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int num : nums)
            ret ^= num;
        return ret;
    }
};

/*
 * Use the bit manipulation XOR's attribute that
 * num ^ num = 0;
 */
