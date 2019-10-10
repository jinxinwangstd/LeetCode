class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        vector<int64_t> num_patterns(n < 10 ? 10 : n + 1, 0);
        num_patterns[0] = 1;
        num_patterns[1] = 2;
        num_patterns[2] = 4;
        num_patterns[3] = 7;
        for (int i = 4; i <= n; i++)
            num_patterns[i] = (((num_patterns[i - 1] * 2) % MOD) + (MOD - num_patterns[i - 4])) % MOD;
        int64_t ans = num_patterns[n];
        for (int i = 0; i < n; i++)
            ans += (num_patterns[i - 0] * num_patterns[n - 1 - i]) % MOD;
        return ans % MOD;
    }
};
