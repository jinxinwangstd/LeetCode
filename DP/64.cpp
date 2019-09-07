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
	// This function finds the path with minimal cost from the left-upper corner to the right-bottom corner in a grid with no obstacles
	// The main idea is bottom-up dynamic programming
	int minPathSum(vector< vector<int> >& grid)
	{
		if (grid.empty())		// corner case: empty grid
			return 0;
		int m = (int) grid.size(), n = (int) grid[0].size();
		vi cur_row(n, 0), next_row(n, 0);			// we only need to maintain two rows at the same time
		int cur_index = m - 1;
		// base case
		cur_row[n - 1] = grid[cur_index][n - 1];
		for (int j = n - 2; j >= 0; --j)
			cur_row[j] = grid[cur_index][j] + cur_row[j + 1];
		if (!cur_index)			// corner case: one-row grid
			return cur_row[0];
		while (cur_index)		// loop until the current row is the first row in the grid
		{
			next_row.assign(n, 0);
			// base case
			next_row[n - 1] = grid[cur_index - 1][n - 1] + cur_row[n - 1];
			for (int j = n - 2; j >= 0; --j)
				next_row[j] = grid[cur_index - 1][j] + min(next_row[j + 1], cur_row[j]);	// recursive relation
			cur_row = next_row;
			--cur_index;
		}
		// return the state of the first element of the first row, i.e. the starting state
		return cur_row[0];
	}
};
