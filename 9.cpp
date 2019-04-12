#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0)			// negative integer must not be palindrome
			return false;
		// get the reverse integer and compare it with the original one
		ll reverse = 0;		// use ll to avoid integer overflow
		int d = x;
		while (d)
		{
			reverse *= 10;
			reverse += (d % 10);
			d /= 10;
		}
		return reverse == x;	// comparison
	}
};
