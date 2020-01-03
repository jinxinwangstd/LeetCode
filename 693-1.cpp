class Solution {
public:
    bool hasAlternatingBits(int n) {
        while (n) {
            int bit = n & 1;
            n >>= 1;
            if (!(bit ^ (n & 1)))
                return false;
        }
        return true;
    }
};
