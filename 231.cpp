#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

// Count the number of bits set in the binary form of n. If it has only one bits set, then it is a power of 2
bool isPowerOfTwo(int n)
{
	if (n <= 0)
		return false;
	int num_bits_set = 0;
	while (n != 0)
	{
		if (n % 2)
			++num_bits_set;
		n >>= 1;
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
