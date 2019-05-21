#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	string countAndSay(int n)
	{
		string ret("1");
		if (n == 1)			// corner case: the first "count and say" string
			return ret;
		// Iterately generate next "count and say" string
		for (int i = 2; i <= n; ++i)
		{
			string next_ret;
			int count = 0;
			char digit = '0';
			for (char c : ret)
			{
				if (c != digit)		// a new consecutive digit sequence appeared, then we record last digit sequence
				{
					if (count)
						next_ret += (to_string(count) + digit);
					count = 1;
					digit = c;
				}
				else				// another same digit appeared, then we increment the count
					++count;
			}
			next_ret += (to_string(count) + digit);		// don't forget the last consecutive digit sequence
			ret = next_ret;
		}
		return ret;
	}
};
