class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0)
            return false;
        while (num) {
            if (!(num ^ 1))
                return true;
            if (num & 3)
                return false;
            num >>= 2;
        }
        return false;
    }
};
