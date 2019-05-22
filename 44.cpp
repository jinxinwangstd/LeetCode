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
	// Bottom-up dynamic programming method to determine whether two substring of s[s_ptr, end) and p[p_ptr, end) is matched or not
	int match(const string& s, const string& p, int s_ptr, int p_ptr)
	{
		int s_len = (int) s.size(), p_len = (int) p.size();
		// base cases
		if (s_ptr == s_len && p_ptr == p_len)
			return 1;
		if (p_ptr == p_len)
			return 0;
		if (s_ptr == s_len && p[p_ptr] != '*')		// here is the reason why we need to have one more element in the memoization table
			return 0;
		if (memo[s_ptr][p_ptr] != -1)				// because s_ptr could be s_len when p[ptr] == '*'
			return memo[s_ptr][p_ptr];
		// recursive relations
		bool ret = false;
		if (p[p_ptr] != '*' && p[p_ptr] != '?')		// p[p_ptr] is alphabet character
			ret = s[s_ptr] == p[p_ptr] && match(s, p, s_ptr + 1, p_ptr + 1);
		else if (p[p_ptr] == '?')					// p[p_ptr] is ?
			ret = match(s, p, s_ptr + 1, p_ptr + 1);
		else										// p[p_ptr] is *
		{
			for (int i = s_ptr; i <= s_len; ++i)		// * could be matched to any length of substring starting from s_ptr
				ret = ret || match(s, p, i, p_ptr + 1);
		}
		return memo[s_ptr][p_ptr] = (int) ret;
	}
	bool isMatch(string s, string p)
	{
		int s_len = (int) s.size(), p_len = (int) p.size();
		vi temp(p_len + 1, -1);			// the memoization table needs to be 1 element longer than the length of p
		memo.assign(s_len + 1, temp);	// the memoization table needs to be 1 element longer than the length of s
		bool ret = (bool) match(s, p, 0, 0);
		return ret;
	}
};
