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
		// main idea is to construct a state machine with three states: 00 -> 01 -> 10 -> 00 for each bit
		int ones = 0, twos = 0;		// ones is the low bits of the state machine, twos is the high bits of the state machine
		for (int num : nums)
		{
			ones = (ones ^ num) & ~twos;
			twos = (twos ^ num) & ~ones;
		}
		return ones;
	}
};
