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
	int singleNumber(vector<int>& nums)
	{
		int ret = 0;
		for (int num : nums)
			ret ^= num;
		return ret;
	}
};
