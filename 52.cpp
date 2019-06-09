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
	// This function counts how many valid solution given the board size
	int countNQueens(int row, vi& cols, vi& diags, vi& reverse_diags)
	{
		int n = (int) cols.size();
		if (row == n)					// we have filled all n rows
			return 1;
		int ret = 0;
		for (int i = 0; i != n; ++i)	// try to place a queen at this position at the 'row'-th row
		{
			if (cols[i])					// check column collision
				continue;
			if (diags[row - i + n - 1])		// check diagonal collision
				continue;
			if (reverse_diags[row + i])		// check reverse diagonal collision
				continue;
			// update the context
			cols[i] = 1;
			diags[row - i + n - 1] = 1;
			reverse_diags[row + i] = 1;
			ret += countNQueens(row + 1, cols, diags, reverse_diags);	// move up to the next row
			// recover the context
			cols[i] = 0;
			diags[row - i + n - 1] = 0;
			reverse_diags[row + i] = 0;
		}
		return ret;
	}
	int totalNQueens(int n)
	{
		vi cols(n, 0), diags(2 * n - 1, 0), reverse_diags(2 * n - 1, 0);
		int ret = countNQueens(0, cols, diags, reverse_diags);		// solve it
		return ret;
	}
};
