class Solution {
public:
    // This function merges a sequence of intervals with no specific order
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty())
            return res;
        // sort the intervals based on the starting time
        sort(intervals.begin(), intervals.end());
        vector<int> cur(2, 0);
        cur[0] = intervals[0][0];
        cur[1] = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            // current interval overlaps with the next interval
            if (cur[1] >= intervals[i][0])
                cur[1] = max(cur[1], intervals[i][1]);
            // no overlap with next interval
            else {
                res.push_back(cur);
                cur[0] = intervals[i][0];
                cur[1] = intervals[i][1];
            }
        }
        // record the last combined interval
        res.push_back(cur);
        return res;
    }
};

/*
 * Greedy
 */
