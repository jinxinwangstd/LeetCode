#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

// Determine whether the 3 form of n has only 1 bit of 1 and all other bits of 0
bool isPowerOfThree(int n)
{
	if (n <= 0)
		return false;
	int num_bits_set = 0;
	while (n != 0)
	{
		int remainder = n % 3;
		if (remainder == 2)
			return false;
		if (remainder == 1)
			++num_bits_set;
		n /= 3;
	}
	return num_bits_set == 1;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	return 0;
}
