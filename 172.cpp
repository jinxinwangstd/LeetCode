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
	int trailingZeroes(int n)
	{
		int exp = (int) (log((double) n) / log(5.0));
		int factor = 1;
		int ret = 0;
		for (int i = 1; i <= exp; ++i)
		{
			factor *= 5;
			ret += n / factor;
		}
		return ret;
	}
};
