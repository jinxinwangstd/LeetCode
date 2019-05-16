#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if (dividend == INT_MIN && divisor == -1)		// corner case: the quotient would be integer overflow
			return INT_MAX;
		// capture the sign of the quotient and use the absolute value to calculate the quotient
		int sign = ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) ? -1 : 1;
		ll abs_dividend = abs((ll) dividend);	// be careful about integer overflow when transform integers to the absolute value
		ll abs_divisor = abs((ll) divisor);
		ll ret = 0;
		int shift = 0;
		while (abs_dividend >= abs_divisor)
		{
			// calculate the biggest quotient which is the power of 2
			while ((abs_divisor << (shift + 1)) <= abs_dividend)
				++shift;
			ret += (1 << shift);
			abs_dividend -= (abs_divisor << shift);
			// reset the shift to calculate the rest quotient
			shift = 0;
		}
		return sign * ret;
	}
};

/*
 * Bit manipulation
 */
