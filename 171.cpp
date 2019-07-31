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
	int titleToNumber(string s)
	{
		int len = s.size(), ret = 0;
		for (int i = 0; i < len; ++i)
		{
			int num = s[i] - 'A' + 1;
			ret *= 26;
			ret += num;
		}
		return ret;
	}
};
