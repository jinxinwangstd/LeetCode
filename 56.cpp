#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class Solution
{
public:
	// This function merges a sequence of intervals with no specific order
	vector< vector<int> > merge(vector< vector<int> >& intervals)
	{
		vector<vi> ret;
		if (intervals.empty())
			return ret;
		// sort the intervals based on the starting time
		sort(intervals.begin(), intervals.end());
		int cur_start = intervals[0][0], cur_end = intervals[0][1];
		for (int i = 1; i != (int) intervals.size(); ++i)
		{
			if (cur_end >= intervals[i][0])			// current interval overlaps with the next interval
				cur_end = max(cur_end, intervals[i][1]);
			else									// no overlap with next interval
			{
				// record the last combined interval
				vi interval(2);
				interval[0] = cur_start;
				interval[1] = cur_end;
				ret.push_back(interval);
				// update the information of current interval
				cur_start = intervals[i][0];
				cur_end = intervals[i][1];
			}
		}
		// record the last combined interval
		vi interval(2);
		interval[0] = cur_start;
		interval[1] = cur_end;
		ret.push_back(interval);
		return ret;
	}
};
