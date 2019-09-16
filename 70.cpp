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
	// This function calculates the number of ways to climb to the n-th stair based on the dynamic programming
	// Similar to the Fibonacci sequence
	int climbStairs(int n)
	{
		if (!n)			// corner case
			return 1;
		int top = 1, bottom = 2;
		// base cases
		if (n == 1)
			return top;
		if (n == 2)
			return bottom;
		int i = 2;
		// recursively calculate the next number
		while (true)
		{
			top += bottom;
			if (n == ++i)
				return top;
			bottom += top;
			if (n == ++i)
				return bottom;
		}
	}
};
