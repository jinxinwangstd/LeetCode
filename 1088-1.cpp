class Solution {
public:
    int mapping[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    int digits[5] = {0, 1, 6, 8, 9};
    int rotate(int64_t num) {
        int res = 0;
        while (num) {
            int digit = num % 10;
            res *= 10;
            res += mapping[digit];
            num /= 10;
        }
        return res;
    }
    int dfs(int64_t num, int N) {
        num *= 10;
        if (num > N)
            return 0;
        int res = 0;
        for (int i = num ? 0 : 1; i < 5; i++) {
            num += digits[i];
            if (num <= N) {
                if (rotate(num) != num)
                    res += 1;
                res += dfs(num, N);
            }
            num -= digits[i];
        }
        return res;
    }
    int confusingNumberII(int N) {
        return dfs(0, N);
    }
};

/*
 * DFS
 * To compose the possible confusing numbers.
 */
