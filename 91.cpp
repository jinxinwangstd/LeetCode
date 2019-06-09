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
	int numDecodings(string s)
	{
		int n = (int) s.size();
		int cur = 0, one_after = 1, two_after = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			if (s[i] == '0')		// '0' has no way to decode
				cur = 0;
			else
			{
				cur = one_after;	// decode current number as one character
				if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))	// another way is to decode current two numbers as one character
					cur += two_after;
			}
			// move to the next number
			two_after = one_after;
			one_after = cur;
		}
		return cur;
	}
};
