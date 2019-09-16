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
	vector<vi> memo;
	int determineMinPath(vector<vi>& dungeon, int x, int y)
	{
		if (memo[x][y] != INT_MAX)
			return memo[x][y];
		int ret = min(determineMinPath(dungeon, x + 1, y), determineMinPath(dungeon, x, y + 1)) - dungeon[x][y];
		return memo[x][y] = ret >= 1 ? ret : 1;
	}
	int calculateMinimumHP(vector<vector<int>>& dungeon)
	{
		int m = dungeon.size(), n = dungeon[0].size();
		vi row(n, INT_MAX);
		memo.assign(m, row);
		int min_health = 0;
		min_health = 1 - dungeon[m - 1][n - 1];
		memo[m - 1][n - 1] = min_health >= 1 ? min_health : 1;
		for (int i = m - 2; i >= 0; --i)
		{
			min_health = memo[i + 1][n - 1] - dungeon[i][n - 1];
			memo[i][n - 1] = min_health >= 1 ? min_health : 1;
		}
		for (int j = n - 2; j >= 0; --j)
		{
			min_health = memo[m - 1][j + 1] - dungeon[m - 1][j];
			memo[m - 1][j] = min_health >= 1 ? min_health : 1;
		}
		int ret = determineMinPath(dungeon, 0, 0);
		return ret;
	}
};
