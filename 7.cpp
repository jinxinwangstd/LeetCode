#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	int reverse(int x)
	{
		bool neg = x < 0;
		ll lx = abs((ll) x);	// abs() has the risk of integer overflow cause abs(INT_MIN) > INT_MAX
		ll ret = 0;
		// Reverse each bit
		while (lx != 0)
		{
			ret *= 10;
			ret += lx % 10;
			lx /= 10;
		}
		if (neg)		// negative result
			ret = -ret;
		if ((!neg && ret > INT_MAX) || (neg && ret < INT_MIN))	// check integer overflow
			ret = 0;
		return (int) ret;
	}
};
