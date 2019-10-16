class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0, digit = 0;
        int carry = 0, sum = 0;
        while (a || b) {
            int temp = (a & 1) ^ (b & 1);
            sum = temp ^ carry;
            carry = ((a & 1) & (b & 1)) | (carry & temp);
            ans |= sum << digit;
            digit++;
            // the default right shift way is arithmetic shift, and we want logical shift
            a >>= 1;
            if (a < 0)
                a &= ~(1 << 31);
            // logical right shift
            b >>= 1;
            if (b < 0)
                b &= ~(1 << 31);
        }
        // ignore the integer overflow part
        if (carry && digit < 32) {
            ans |= sum << digit;
            digit++;
            carry = 0;
        }
        return ans;
    }
};
