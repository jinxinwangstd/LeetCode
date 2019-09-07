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
	int minimumTotal(vector< vector<int> >& triangle)
	{
		int height = triangle.size();
		vi cur(height), next(height);
		int depth = 0;
		cur[0] = triangle[depth][0];
		while (depth + 1 < height)
		{
			++depth;
			for (int i = 0; i <= depth; ++i)
			{
				if (i == 0)
					next[i] = cur[i] + triangle[depth][i];
				else if (i == depth)
					next[i] = cur[i - 1] + triangle[depth][i];
				else
					next[i] = min(cur[i], cur[i - 1]) + triangle[depth][i];
			}
			cur = next;
		}
		int ret = INT_MAX;
		for (int i = 0; i < height; ++i)
			ret = min(ret, cur[i]);
		return ret;
	}
};
