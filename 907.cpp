class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& A) {
        vector<pair<int, int>> stack;
        int res = 0;
        int sum_stack = 0;
        for (int i = 0; i < A.size(); i++) {
            while (!stack.empty() && stack.back().first >= A[i]) {
                int val = stack.back().first, pos = stack.back().second;
                stack.pop_back();
                sum_stack -= (stack.empty() ? pos + 1 : pos - stack.back().second) * val;
            }
            res += sum_stack;
            res %= MOD;
            res += (stack.empty() ? i + 1 : i - stack.back().second) * A[i];
            res %= MOD;
            sum_stack += (stack.empty() ? i + 1 : i - stack.back().second) * A[i];
            sum_stack %= MOD;
            stack.push_back(make_pair(A[i], i));
        }
        return res;
    }
};

/*
 * Monotonic stack
 */
