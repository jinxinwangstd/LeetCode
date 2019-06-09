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
	// This function calculates the number of unique paths from the top-left corner to the bottom-right corner in an m * n grid
	// The main idea is the dynamic programming algorithm with a memoization table for all states
	int uniquePaths(int m, int n)
	{
		// for a specific position, the number of path is determined only by its right neighbor and its bottom neighbor
		vi cur_row(n, 0), next_row(n, 0);	// we only need to record two adjacent rows in a time
		// base case is the bottom row, where the number of paths for each position is 1
		int cur_index = m - 1;
		for (int j = 0; j != n; ++j)
			cur_row[j] = 1;
		// corner case: there is only one row in the grid
		if (!cur_index)
			return cur_row[0];
		// Iteratively update the memoization table, gradually move upwards
		while (cur_index > 0)		// when current row is the 1-th, then next row would be the 0-th row
		{
			next_row.assign(n, 0);
			next_row[n - 1] = 1;	// base case: the right-most column is 1 because we have to move downwards
			// gradually filled the states in the next row
			for (int j = n - 2; j >= 0; --j)
				next_row[j] = next_row[j + 1] + cur_row[j];		// recursive relation between different states
			// move upwards
			cur_row = next_row;
			cur_index--;
		}
		// the answer is the starting state
		return next_row[0];
	}
};
