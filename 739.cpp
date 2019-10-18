class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> s;
        int n = T.size();
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            int num = 0;
            while (!s.empty() && T[i] >= s.top().first)
                s.pop();
            if (!s.empty())
                num = s.top().second - i;
            res[i] = num;
            s.push(make_pair(T[i], i));
        }
        return res;
    }
};

/*
 * Monotonic stack
 */
