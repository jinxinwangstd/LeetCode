#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    static bool compare(vector<int>& p, vector<int>& q) {
        if (p[0] < q[0])
            return true;
        else if (p[0] > q[0])
            return false;
        else
            return p[1] < q[1];
    }
    vector<int> partitionLabels(string S) {
        vector<vector<int>> positions(26, vector<int>());
        int n = S.size();
        for (int i = 0; i < n; i++) {
            if (positions[S[i] - 'a'].empty()) {
                positions[S[i] - 'a'].push_back(i);
                positions[S[i] - 'a'].push_back(i);
            }
            else {
                positions[S[i] - 'a'][1] = i;
            }
        }
        vector<vector<int>> intervals;
        for (int i = 0; i < 26; i++)
            if (!positions[i].empty())
                intervals.push_back(positions[i]);
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> res;
        int start = -1, end = -1;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                end = max(end, intervals[i][1]);
            }
            else {
                if (start >= 0)
                    res.push_back(end - start + 1);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        if (start >= 0)
            res.push_back(end - start + 1);
        return res;
    }
};
