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
	// This function traverses through a matrix in the spiral order and returns element sequence in that order
	// The matrix may not be square, so that the traverse way should be more flexible
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		vi ret;
		if (matrix.empty() || matrix[0].empty())
			return ret;
		int num_row = (int) matrix.size(), num_col = (int) matrix[0].size();
		// set the boundary of current layer (outer-most layer)
		int row_start = 0, row_end = num_row - 1;
		int col_start = 0, col_end = num_col - 1;
		int num_elem = num_row * num_col;
		int r = row_start, c = col_start;
		// we traverse the matrix layer by layer
		while (num_elem)
		{
			ret.push_back(matrix[r][c]);
			if (r == row_start && c != col_end)			// at the top part of the current layer
				++c;
			else if (r != row_end && c == col_end)		// at the right part of the current layer
				++r;
			else if (r == row_end && c != col_start)	// at the bottom part of the current layer
				--c;
			else										// at the left part of the current layer
				--r;
			if (r == row_start && c == col_start)	// we have finish current layer, then move the start position to the next inner layer
			{
				// update the boundary to the next layer
				++row_start;
				++col_start;
				--row_end;
				--col_end;
				// move the start position
				r = row_start;
				c = col_start;
			}
			--num_elem;		// count the elements we have traversed
		}
		return ret;
	}
};
