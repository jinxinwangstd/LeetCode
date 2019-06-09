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
	// This function calculates the largest rectangle area in a histogram
	int largestRectangleArea(vector<int>& heights)
	{
		int ret = 0;
		stack<int> s;
		s.push(-1);
		// from left to right, we gradually push every index into the stack and maintain the representing histogram being non-decreasing
		for (int i = 0; i != (int) heights.size(); ++i)
		{
			if (s.top() != -1 && heights[i] < heights[s.top()])
			{
				int index;
				// pop out all index which is higher than the current index to maintain non-decreasing
				for (index = s.top(); index != -1 && heights[index] > heights[i]; index = s.top())
				{
					s.pop();
					// In the rectangle, right bound is the bar to the left of the bar with index i, left bound is itself, and the height is its own height
					int cur_area = heights[index] * (i - s.top() - 1);
					ret = max(ret, cur_area);
				}
			}
			s.push(i);
		}
		// Now all index has been processed and the left histogram is non-decreasing, then we calculate every possible largest rectangle
		for (int index = s.top(); index != -1; index = s.top())
		{
			s.pop();
			// In the rectangle, right bound is the right-most bar, left bound is itself, and the height is its own height
			int cur_area = heights[index] * (heights.size() - s.top() - 1);
			ret = max(ret, cur_area);
		}
		return ret;
	}
};
