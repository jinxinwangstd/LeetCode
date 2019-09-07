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
		for (int i = 0; i != (int) heights.size(); ++i)
		{
			if (s.top() != -1 && heights[i] < heights[s.top()])
			{
				int index;
				for (index = s.top(); index != -1 && heights[index] > heights[i]; index = s.top())
				{
					s.pop();
					int cur_area = heights[index] * (i - s.top() - 1);
					ret = max(ret, cur_area);
				}
			}
			s.push(i);
		}
		for (int index = s.top(); index != -1; index = s.top())
		{
			s.pop();
			int cur_area = heights[index] * (heights.size() - s.top() - 1);
			ret = max(ret, cur_area);
		}
		return ret;
	}
	// This function calculates the rectangle with maximum area in a matrix
	int maximalRectangle(vector< vector<char> >& matrix)
	{
		if (matrix.empty() || matrix[0].empty())		// corner case: empty matrix
			return 0;
		int m = matrix.size(), n = matrix[0].size();
		// record the vertical height at each horizontal line
		vi row(n, 0);
		vector<vi> heights(m, row);
		for (int j = 0; j != n; ++j)
		{
			int height = 0;
			for (int i = 0; i != m; ++i)
			{
				if (matrix[i][j] == '0')
					height = 0;
				else
					++height;
				heights[i][j] = height;
			}
		}
		// calculate maximum rectangle at each horizontal line
		int ret = 0;
		for (int i = 0; i != m; ++i)
			ret = max(ret, largestRectangleArea(heights[i]));
		return ret;
	}
};
