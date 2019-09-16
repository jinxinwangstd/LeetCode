#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        vector<vector<int>>::iterator iter = intervals.begin();
        while (iter != intervals.end()) {
            vector<vector<int>>::iterator next_iter;
            if ((next_iter = next(iter, 1)) == intervals.end())
                break;
            if ((*next_iter)[0] < (*iter)[1]) {
                if ((*iter)[1] > (*next_iter)[1])
                    iter = intervals.erase(iter);
                else
                    intervals.erase(next_iter);
                count++;
            }
            else
                iter++;
        }
        return count;
    }
};
