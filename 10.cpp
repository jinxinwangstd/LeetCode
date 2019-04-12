#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	// Bottom-up dynamic programming method
	bool isMatch(string s, string p)
	{
		vector< vector<bool> > memo;	// memo to store intermediate result
		// Initialize the memo element
		memo.assign(s.size() + 1, vector<bool>(p.size() + 1, false));
		memo[s.size()][p.size()] = true;

		for (int i = s.size(); i >= 0; --i)
			for (int j = p.size() - 1; j >= 0; --j)
			{
				bool first_match = (i < s.size()) && ((s[i] == p[j]) || p[j] == '.');	// check whether the first element is matching
				// up recursion
				if (j + 1 < p.size() && p[j + 1] == '*')
					// for wildcard, either it counts zero character or counts one or more
					memo[i][j] = memo[i][j + 2] || (first_match && memo[i + 1][j]);
				else
					// for no wildcard, match then both advance
					memo[i][j] = first_match && memo[i + 1][j + 1];
			}
		return memo[0][0];
	}
};
