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
	// This function determines whether a target appears in a matrix, which is in increasing order from left to right, from upwards to downwards
	// The main idea is divide and conquer
	bool searchMatrix(vector< vector<int> >& matrix, int target)
	{
		if (matrix.empty() || matrix[0].empty())	// corner case: if the matrix is 0-size, then the target must not appear there
			return false;
		int m = (int) matrix.size(), n = (int) matrix[0].size();
		// search the row the target should be in using binary search
		int lo = 0, hi = m - 1, mid;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (target < matrix[mid][0])
				hi = mid - 1;
			else if (target > matrix[mid][0])
				lo = mid + 1;
			else
				break;
		}
		int i = mid;
		// The target should be greater than next row's start, and less than the last row's end
		if (target < matrix[mid][0] && i > 0)
			--i;
		else if (target > matrix[mid][n - 1] && i < m - 1)
			++i;
		// search the column the target should be in using binary search
		lo = 0;
		hi = n - 1;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (target < matrix[i][mid])
				hi = mid - 1;
			else if (target > matrix[i][mid])
				lo = mid + 1;
			else
				return true;
		}
		return false;
	}
};
