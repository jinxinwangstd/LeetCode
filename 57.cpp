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
	// This function inserts the new interval into the sequence of intervals (originally sorted based on the starting time) and merges them
	vector< vector<int> > insert(vector< vector<int> >& intervals, vector<int>& newInterval)
	{
		if (intervals.empty())			// corner case: the original sequence of intervals is empty, we just insert the new interval into it
		{
			intervals.push_back(newInterval);
			return intervals;
		}
		vector<vi>::iterator iter = intervals.begin(), next_iter;
		// find the proper position to insert the new interval so that the order is still maintained
		if (newInterval[0] <= intervals[0][0])		// insert into the head
		{
			next_iter = iter;
		}
		else										// insert into the middle
		{
			while (true)
			{
				next_iter = next(iter);
				if ((*iter)[0] <= newInterval[0] && (next_iter == intervals.end() || (*next_iter)[0] >= newInterval[0]))
					break;
				++iter;
			}
		}
		// insert the new interval into the proper position
		next_iter = intervals.insert(next_iter, newInterval);
		if (next_iter != intervals.begin())
			iter = prev(next_iter);
		else
		{
			iter = next_iter;
			next_iter = next(iter);
		}
		// try to merge the new interval with its previous and following intervals
		if ((*iter)[1] < newInterval[0])	// if its previous interval does not overlap with it, then we don't need to consider it
		{
			++iter;
			next_iter = next(iter);
		}
		// starting from the element pointed by 'iter', trying to merge the following intervals
		while (next_iter != intervals.end())
		{
			if ((*iter)[1] >= (*next_iter)[0])
			{
				(*iter)[1] = max((*iter)[1], (*next_iter)[1]);
				next_iter = intervals.erase(next_iter);
			}
			else
				break;
		}
		return intervals;
	}
};
