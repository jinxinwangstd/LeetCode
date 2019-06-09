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
	// This function generates the matrix in which we arrange elements in spiral order starting from 1
	// The main idea is to arrange the elements layer by layer
	vector<vector<int>> generateMatrix(int n)
	{
		vi row(n, 0);
		vector<vi> matrix(n, row);
		// The boundary of the current layer (the first layer)
		int row_start = 0, row_end = n - 1;
		int col_start = 0, col_end = n - 1;
		int r = row_start, c = col_start;
		int num_elem = n * n, i = 1;
		while (i <= num_elem)
		{
			matrix[r][c] = i;
			if (r == row_start && c != col_end)			// at the top part of current layer
				++c;
			else if (r != row_end && c == col_end)		// at the right part of current layer
				++r;
			else if (r == row_end && c != col_start)	// at the bottom part of current layer
				--c;
			else 										// at the left part of current layer
				--r;
			if (r == row_start && c == col_start)		// we finish the current layer then move to the next inner layer
			{
				// update the boundary
				++row_start;
				++col_start;
				--row_end;
				--col_end;
				// move the starting position
				r = row_start;
				c = col_start;
			}
			// count the elements we have arranged
			++i;
		}
		return matrix;
	}
};
