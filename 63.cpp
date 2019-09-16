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
	// This function calculates the number of unique paths from the top-left corner to the bottom-right corner in an m * n grid with obstacle inside
	// The main idea is the dynamic programming algorithm with a memoization table for all states
	int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid)
	{
		if (obstacleGrid.empty())		// corner case: the grid is empty
			return 0;
		int m = (int) obstacleGrid.size(), n = (int) obstacleGrid[0].size();
		// we only need to record two adjacent rows in a time
		vector<ll> cur_row(n, -1), next_row(n, -1);			// based on the estimation of results, we need int64_t to store the state
		int cur_index = m - 1;
		cur_row[n - 1] = obstacleGrid[m - 1][n - 1] ? 0 : 1;	// base case: the destination state
		// filled the last row based on the recursive relation
		for (int j = n - 2; j >= 0; --j)
		{
			if (obstacleGrid[cur_index][j])
				cur_row[j] = 0;
			else
				cur_row[j] = cur_row[j + 1];
		}
		// corner case: there is only one row in the grid
		if (!cur_index)
			return cur_row[0];
		// Iteratively update the memoization table, gradually move upwards
		while (cur_index > 0)
		{
			next_row.assign(n, -1);
			// base case: the right-most element is the same as its corresponding element in the next row
			if (obstacleGrid[cur_index - 1][n - 1])
				next_row[n - 1] = 0;
			else
				next_row[n - 1] = cur_row[n - 1];
			// gradually fill other state in the same row
			for (int j = n - 2; j >= 0; --j)
			{
				if (obstacleGrid[cur_index - 1][j])
					next_row[j] = 0;
				else
					next_row[j] = cur_row[j] + next_row[j + 1];
			}
			cur_row = next_row;
			--cur_index;
		}
		// the answer is the starting state
		return next_row[0];
	}
};
