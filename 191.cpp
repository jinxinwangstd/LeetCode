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
	int hammingWeight(uint32_t n)
	{
		uint32_t mask = 1;
		int ret = 0;
		for (int i = 0; i < 32; ++i)
		{
			// if the shifted number is 0, which means all rest bits are 0
			if (!n)
				return ret;
			// check whether the lowest bit is 1 or not
			if (n & mask)
				ret++;
			// move to the next bit
			n >>= 1;
		}
		return ret;
	}
};
