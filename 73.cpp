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
	// This function sets the rows and columns a zero element belongs to into zeros
	void setZeroes(vector< vector<int> >& matrix)
	{
		if (matrix.empty())		// corner case: we don't need to do anything if the matrix is 0-size
			return;
		int m = (int) matrix.size(), n = (int) matrix[0].size();
		// vectors to record the rows and columns need to be set to 0
		vi rows(m, 0), cols(n, 0);
		int row_i = 0, col_i = 0;
		// scan each rows and columns to complete the record
		// the scanning order is the first row, then the first column, then the second row, then the second column, and so on
		while (row_i != m || col_i != n)
		{
			if (row_i < m && !rows[row_i])		// if this row is already set, we can skip it
			{
				for (int j = 0; j != n; ++j)
				{
					if (!matrix[row_i][j])		// met a zero element, set the record for its row number and column number
					{
						rows[row_i] = 1;
						cols[j] = 1;
						break;					// current row is set, then we can finish scanning this row
					}
				}
			}
			if (row_i < m)
				++row_i;
			if (col_i < n && !cols[col_i])		// if this column is already set, we can skip it
			{
				for (int i = 0; i != m; ++i)
				{
					if (!matrix[i][col_i])		// met a zero element, set the record for its row number and column number
					{
						rows[i] = 1;
						cols[col_i] = 1;
						break;					// current column is set, then we can finish scanning this column
					}
				}
			}
			if (col_i < n)
				++col_i;
		}
		// According to our record, set those rows and columns
		for (int i = 0; i != m; ++i)
		{
			if (rows[i])
			{
				for (int j = 0; j != n; ++j)
					matrix[i][j] = 0;
			}
		}
		for (int j = 0; j != n; ++j)
		{
			if (cols[j])
			{
				for (int i = 0; i != m; ++i)
					matrix[i][j] = 0;
			}
		}
		return;
	}
};
