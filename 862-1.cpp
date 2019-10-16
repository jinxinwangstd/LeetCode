class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> prefix(n + 1, 0);
        deque<int> q;
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + A[i - 1];
        q.push_back(0);
        int ans = INT_MAX;
        // we try to find the best left bound for each right bound i
        for (int i = 1; i <= n; i++) {
            while (!q.empty() && prefix[q.front()] + K <= prefix[i]) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            // i become a possible left bound for each right bound greater than i
            // all possible left bound whose position is left than i and value is greater than i cannot be a better left bound choice than i
            // cause if i is a valid left bound, i is tigher than all other lefter bounds
            // and if is not a valid left bound, all other lefter bounds must be invalid
            // so we should maintain the queue in increasing order
            while (!q.empty() && prefix[q.back()] >= prefix[i])
                q.pop_back();
            q.push_back(i);
        }
        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }
};
