#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

class Solution
{
public:
	int R, C;
	void dfs(vector< vector<char> >& grid, int r, int c, char c1, char c2)
	{
		if (r < 0 || r >= R || c < 0 || c >= C)
			return;
		if (grid[r][c] != c1)
			return;
		int ans = 1;
		grid[r][c] = c2;
		for (int i = 0; i < 4; ++i)
			dfs(grid, r + dr[i], c + dc[i], c1, c2);
		return;
	}
	int numIslands(vector< vector<char> >& grid)
	{
		if (grid.empty() || grid[0].empty())
			return 0;
		R = (int)grid.size();
		C = (int)grid[0].size();
		int ret = 0;
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				if (grid[i][j] == '1')
				{
					ret++;
					dfs(grid, i, j, '1', '2');
				}
		return ret;
	}
};
