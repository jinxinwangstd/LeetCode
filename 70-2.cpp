class Solution {
public:
    int climbStairs(int n) {
        int first = 1, second = 1;
        for (int i = 1; i < n; i++) {
            int res = first + second;
            first = second;
            second = res;
        }
        return second;
    }
};

/*
 * Dynamic programming.
 * Fibonacci sequence.
 */
