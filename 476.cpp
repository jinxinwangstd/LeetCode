class Solution {
public:
    int findComplement(int num) {
        int64_t all_ones = 1;
        while (all_ones <= num)
            all_ones <<= 1;
        all_ones -= 1;
        return num ^ all_ones;
    }
};
