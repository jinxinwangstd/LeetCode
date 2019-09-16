#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    static bool compareStart(vector<int>& p, vector<int>& q) {
        return p[0] < q[0];
    }
    static bool compareEnd(vector<int>& p, vector<int>& q) {
        return p[1] < q[1];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> copy(intervals);
        sort(intervals.begin(), intervals.end(), compareStart);
        sort(copy.begin(), copy.end(), compareEnd);
        int start_i = 0, end_i = 0;
        int time = -1, res = 0, count = 0;
        while (start_i < n && end_i < n) {
            if (intervals[start_i][0] < copy[end_i][1]) {
                time = intervals[start_i][0];
                count++;
                start_i++;
                res = max(res, count);
            }
            else if (intervals[start_i][0] > copy[end_i][1]) {
                time = copy[end_i][1];
                count--;
                end_i++;
            }
            else {
                start_i++;
                end_i++;
            }
        }
        return res;
    }
};
