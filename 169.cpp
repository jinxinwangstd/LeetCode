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
	int majorityElement(vector<int>& nums)
	{
		int candidate = 0, times = 0;

		for (int num : nums)
		{
			if (!times)
			{
				candidate = num;
				times = 1;
			}
			else
			{
				times += candidate == num ? 1 : -1;
			}
		}
		return candidate;
	}
};
