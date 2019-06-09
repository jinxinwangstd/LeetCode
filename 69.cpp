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
	// Calculate the square root based on the divide and conquer algorithms
	int mySqrt(int x)
	{
		int hi = x, lo = 0;
		int mid = 0;
		while (hi >= lo)
		{
			mid = (hi + lo) / 2;
			// watch out overflow risk
			if ((ll) mid * mid > x)
			{
				hi = mid - 1;
			}
			else if ((ll) mid * mid < x)
			{
				lo = mid + 1;
			}
			else
				return mid;
		}
		if (mid * mid > x)		// we only return the truncated result so the square of the result must be <= x
			--mid;
		return mid;
	}
};
