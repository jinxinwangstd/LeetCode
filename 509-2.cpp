class Solution {
public:
    int fib(int N) {
        if (N == 0)
            return 0;
        int first = 0, second = 1;
        for (int i = 1; i < N; i++) {
            int res = first + second;
            first = second;
            second = res;
        }
        return second;
    }
};

/*
 * Dynamic programming.
 */
