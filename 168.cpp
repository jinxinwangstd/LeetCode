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
	string convertToTitle(int n)
	{
		string ret;
		while (n)
		{
			n -= 1;
			char c = 'A' + (n % 26);
			ret = c + ret;
			n = n / 26;
		}
		return ret;
	}
};
