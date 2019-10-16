class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        int ret = 0;
        for (int i = 0; i < 32; ++i) {
            // if the shifted number is 0, which means all rest bits are 0
            if (!n)
                return ret;
            // check whether the lowest bit is 1 or not
            if (n & mask)
                ret++;
            // move to the next bit
            n >>= 1;
        }
        return ret;
    }
};
