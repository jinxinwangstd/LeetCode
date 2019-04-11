#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	static const int maxn = 1000 + 5;
	int memo[maxn][maxn];
	int findLongestPalindrome(const string& s, int i, int j)
	{
		if (i == j)
			return 0;
		if (i + 1 == j)
			return memo[i][j] = 1;
		if (memo[i][j] != 0)
			return memo[i][j];
		if (s[i] == s[j - 1] && findLongestPalindrome(s, i + 1, j - 1) == (j - i - 2))
			return memo[i][j] = j - i;
		else
			return memo[i][j] = max(findLongestPalindrome(s, i + 1, j), findLongestPalindrome(s, i, j - 1));
	}
	// TODO(Alex): Using Manacher's algorithm
	string longestPalindrome(string s)
	{
		memset(memo, 0, size(memo));
		int ret = findLongestPalindrome(s, 0, (int)s.size());
		for (int i = 0; i != (int)s.size(); ++i)
		{
			if (memo[i][i + ret] == ret)
				return s.substr(i, ret);
		}
		return string();
	}
};
