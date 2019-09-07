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
	vi memo;
	bool isPalindrome(const string& s, int start, int end)
	{
		int i = start, j = end - 1;
		while (i < j)
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	int countMinCut(const string& s, int start)
	{
		if (start == s.size())
			return 0;
		if (memo[start] != -1)
			return memo[start];
		int ret = INT_MAX;
		for (int i = start + 1; i <= s.size(); ++i)
		{
			if (isPalindrome(s, start, i))
				ret = min(ret, 1 + countMinCut(s, i));
		}
		return memo[start] = ret;
	}
	int minCut(string s)
	{
		memo.assign(s.size(), -1);
		return countMinCut(s, 0) - 1;
	}
};
