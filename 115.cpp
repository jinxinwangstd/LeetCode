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
	vector<vi> memo;
	int countSubsequence(const string& s, const string& t, int ps, int pt)
	{
		if (pt < 0)
			return 1;
		if (ps < 0)
			return 0;
		if (memo[ps][pt] != -1)
			return memo[ps][pt];
		int ret = 0;
		if (s[ps] == t[pt])
			ret += countSubsequence(s, t, ps - 1, pt - 1);
		ret += countSubsequence(s, t, ps - 1, pt);
		return memo[ps][pt] = ret;
	}
	int numDistinct(string s, string t)
	{
		vi row(t.size(), -1);
		memo.assign(s.size(), row);
		return countSubsequence(s, t, s.size() - 1, t.size() - 1);
	}
};
