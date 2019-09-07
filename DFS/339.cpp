#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	int rDepthSum(vector<NestedInteger>& nestedList, int depth)
	{
		int num = nestedList.size(), ans = 0;
		for (int i = 0; i != num; ++i)
		{
			NestedInteger ni = nestedList[i];
			if (ni.isInteger())
				ans += depth * ni.getInteger();
			else
				ans += rDepthSum(ni.getList(), depth + 1);
		}
		return ans;
	}

	int depthSum(vector<NestedInteger>& nestedList)
	{
		int ret = rDepthSum(nestedList, 1);
		return ret;
	}
};
