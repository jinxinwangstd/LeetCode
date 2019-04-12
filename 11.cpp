#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int i = 0, j = height.size() - 1;	// pointers to the left and right bound
		int maxarea = 0;
		while (i != j)
		{
			maxarea = max(maxarea, min(height[i], height[j]) * (j - i));
			// we always seek to change the lower bound as change the higher bound would never increase the result
			height[i] < height[j] ? ++i : --j;
		}
		return maxarea;
	}
};
