class Solution {
public:
    uint32_t lowbit(int64_t x) {
        return x & -x;
    }
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res++;
            n -= lowbit(n);
        }
        return res;
    }
};
