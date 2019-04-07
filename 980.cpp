#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	const int dr[4] = {0, 1, 0, -1};
	const int dc[4] = { -1, 0, 1, 0};
	int R, C, ne, start_r, start_c;

	int dfs(int r, int c, int num, vector< vector<int> >& grid, vector< vector<int> >& dfs_num)
	{
		if (r < 0 || r >= R || c < 0 || c >= C)
			return 0;
		if (dfs_num[r][c])
			return 0;
		if (grid[r][c] == 2)
			return num == ne ? 1 : 0;
		if (grid[r][c] == -1)
			return 0;
		int ans = 0;
		dfs_num[r][c] = 1;
		for (int d = 0; d != 4; d++)
			ans += dfs(r + dr[d], c + dc[d], num + 1, grid, dfs_num);
		dfs_num[r][c] = 0;
		return ans;
	}

	int uniquePathsIII(vector<vector<int> >& grid)
	{
		R = grid.size();
		C = grid[0].size();
		vector<int> row(C, 0);
		vector< vector<int> > dfs_num(R, row);
		ne = 0;
		for (int i = 0; i != R; ++i)
		{
			for (int j = 0; j != C; ++j)
			{
				if (grid[i][j] == 1)
				{
					start_r = i;
					start_c = j;
					++ne;
				}
				else if (grid[i][j] == 0)
					++ne;
			}
		}
		int ret = dfs(start_r, start_c, 0, grid, dfs_num);
		return ret;
	}
};
