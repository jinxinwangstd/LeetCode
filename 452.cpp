#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        ll start = LLONG_MIN, end = LLONG_MIN;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (points[i][0] > end) {
                if (end != LLONG_MIN)
                    count++;
                start = points[i][0];
                end = points[i][1];
            }
            else {
                start = max(start, (ll)points[i][0]);
                end = min(end, (ll)points[i][1]);
            }
        }
        if (end != LLONG_MIN)
            count++;
        return count;
    }
};
