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
	bool isOneEditDistance(string s, string t)
	{
		int si = 0, ti = 0;
		while (si < s.size() && ti < t.size())
		{
			if (s[si] != t[ti])
				break;
			si++;
			ti++;
		}
		if (si == s.size() && ti == t.size())
			return false;
		// insert a character to s
		int sj = si, tj = ti + 1;
		while (sj < s.size() && tj < t.size())
		{
			if (s[sj] != t[tj])
				break;
			sj++;
			tj++;
		}
		if (sj == s.size() && tj == t.size())
			return true;
		// delete a character in s
		sj = si + 1;
		tj = ti;
		while (sj < s.size() && tj < t.size())
		{
			if (s[sj] != t[tj])
				break;
			sj++;
			tj++;
		}
		if (sj == s.size() && tj == t.size())
			return true;
		// change a character
		sj = si + 1;
		tj = ti + 1;
		while (sj < s.size() && tj < t.size())
		{
			if (s[sj] != t[tj])
				break;
			sj++;
			tj++;
		}
		if (sj == s.size() && tj == t.size())
			return true;
		return false;
	}
};
