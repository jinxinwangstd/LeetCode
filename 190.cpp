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
	uint32_t reverseBits(uint32_t n)
	{
		uint32_t ret = 0;
		for (int i = 0; i < 32; ++i)
		{
			ret = ret << 1;
			uint bit = n % 2;
			ret |= bit;
			n = n >> 1;
		}
		return ret;
	}
};
