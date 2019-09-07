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
	// This function determines whether we can jump to the last step based on greedy algorithm
	bool canJump(vector<int>& nums)
	{
		int len = (int) nums.size();
		vi limits(nums);	// record the farthest position a jump can reach for each position
		for (int i = 0; i != len; ++i)
			limits[i] = limits[i] + i;
		int cur = 0, next = cur, next_limit = cur;
		// choose which position (next) we jump to based on the range it can reach
		while (cur < len)
		{
			if (limits[cur] >= len - 1)		// if we can directly jump to the end, then we can get the conclusion
				return true;
			// scan each position we can jump to and choose the one with farthest range
			for (int i = cur + 1; i <= limits[cur]; ++i)
			{
				if (limits[i] > next_limit)
				{
					next_limit = limits[i];
					next = i;
				}
			}
			// we cannot move forward anyway, then returning false
			if (next == cur)
				return false;
			// move up to the next position
			cur = next;
		}
		// we have reached the end, then returning true
		return true;
	}
};
