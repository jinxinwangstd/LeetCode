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
	const int num = 4;
	// This function rotates a matrix with constant extra space
	// The basic idea is to move single element at one time
	void rotate(vector< vector<int> >& matrix)
	{
		if (matrix.empty())		// corner case: the matrix is empty so we need not to rotate
			return;
		int len = (int) matrix.size();
		// Loop through the starting positions for all rotating sets
		for (int i = 0; i != len / 2; ++i)
		{
			int col_start = i, col_end = len - 1 - i;
			for (int j = col_start; j != col_end; ++j)
			{
				// the position of current element to be rotated, and for now it is the first one in a set
				int row = i, col = j;
				int elem = matrix[row][col];
				// we rotate four elements as a set
				for (int k = 0; k != num; ++k)
				{
					// calculate the position the current element would be moved into
					int next_row = col;
					int next_col = len - 1 - row;
					int next_elem = matrix[next_row][next_col];		// record the next element to be overwritten by the current element
					matrix[next_row][next_col] = elem;				// move or rotate or overwrite
					// move up to the next element
					elem = next_elem;
					row = next_row;
					col = next_col;
				}
			}
		}
		return;
	}
};
