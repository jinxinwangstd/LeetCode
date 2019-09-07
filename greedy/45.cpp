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
	int jump(vector<int>& nums)
	{
		if (nums.empty())		// corner case: nums is empty so that we need not to jump
			return 0;
		int len = (int) nums.size();
		// record the right-most position we can jump to at each position
		vi limits(len);
		for (int i = 0; i != len; ++i)
			limits[i] = i + nums[i];
		int cur = 0, step = 0, limit = limits[cur];
		// choose where we jump to based on a greedy policy
		while (cur < len - 1)
		{
			if (limit >= len - 1)	// if we can jump to the end at current position, just jump once
			{
				++step;
				break;
			}
			// When we cannot, we choose the next position where we can jump to farest position
			int next, next_limit = 0;		// next_limit record the limits of next possible position
			for (int i = cur + 1; i <= limit; ++i)
				if (limits[i] > next_limit)
				{
					next_limit = limits[i];
					next = i;
				}
			// jump to the next position
			++step;
			cur = next;
		}
		return step;
	}
};
