class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_two = 0;
        for (int num : nums)
            xor_two ^= num;
        int i = 0;
        while (!(xor_two & (1 << i)))
            i++;
        vector<int> res(2, 0);
        for (int num : nums) {
            if (num & (1 << i))
                res[1] ^= num;
            else
                res[0] ^= num;
        }
        return res;
    }
};

/*
 * First, we calculate the xor product of all numbers, and the result is xor of two target numbers.
 ***********
 * Cause they are different, at least one bit of the target two numbers are different, in result the corresponding bit in xor result is set.
 * According to this bit, we can separate the array into two parts, which have one single number respectively.
 **********
 * Then we calculate the XOR product of two parts, get the result.
 */
