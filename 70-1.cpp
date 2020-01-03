class Solution {
public:
    int climbStairs(int n) {
        if (!n)
            return 1;
        int top = 1, bottom = 2;
        // base cases
        if (n == 1)
            return top;
        if (n == 2)
            return bottom;
        int i = 2;
        // recursively calculate the next number
        while (true) {
            top += bottom;
            if (n == ++i)
                return top;
            bottom += top;
            if (n == ++i)
                return bottom;
        }
    }
};
