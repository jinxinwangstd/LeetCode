#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

int minCostII(vector<vector<int> >& costs)
{
	int n = costs.size();	// number of houses
	if (!n)
		return 0;
	int k = costs[0].size();	// number of colors
	int memo[n][k];		// n*k states: painted n houses with the nearby house having k colors
	memset(memo, 0, sizeof(memo));	// the cost of painting 0 house is 0
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j != k; ++j)
		{
			int ans = INT_MAX;
			// Try every possible color
			for (int c = 0; c != k; ++c)
			{
				if (c != j)
					ans = min(ans, costs[i - 1][c] + memo[i - 1][c]);	// recurrence relation
			}
			memo[i][j] = ans;
		}
	}
	// To arrange the color of the last element without restriction of adjacent house
	int ans = INT_MAX;
	for (int j = 0; j != k; ++j)
		ans = min(ans, costs[n - 1][j] + memo[n - 1][j]);
	return ans;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	return 0;
}
