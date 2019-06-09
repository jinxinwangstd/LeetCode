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
	vector<vi> memo;
	int countTrees(int start, int end)
	{
		if (start > end)			// base case: empty tree
			return 1;
		if (memo[start][end])		// visited state
			return memo[start][end];
		int ret = 0;
		// try all possible root values
		for (int i = start; i <= end; ++i)
		{
			int left_count = countTrees(start, i - 1);
			int right_count = countTrees(i + 1, end);
			ret += left_count * right_count;
		}
		return memo[start][end] = ret;
	}
	// This function counts the number of unique BSTs storing values 1 to n based on dynamic programming algorithm
	int numTrees(int n)
	{
		if (!n)
			return 0;
		vi row(n + 1, 0);
		memo.assign(n + 1, row);
		return countTrees(1, n);
	}
};
