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
	// Recursively arrange next valid parenthesis from left to right when we have arranged "l" number of left parentheses and "r" number of right parentheses and the total number of left and right parentheses should be n respectively
	void recurArrange(vector<string>& ret, string& s, int n, int l, int r)
	{
		if (l == n && r == n)		// base case: we have arranged enough number of parentheses
		{
			ret.push_back(s);
			return;
		}
		if (l == r)					// we have arranged equal number of left and right parentheses
		{
			s[l + r] = '(';
			recurArrange(ret, s, n, l + 1, r);
		}
		else if (l > r)				// the number of left parentheses we have arranged > the number of right parentheses
		{
			if (l < n)	// arrange a left parenthesis
			{
				s[l + r] = '(';
				recurArrange(ret, s, n, l + 1, r);
			}
			// arrange a right parenthesis
			s[l + r] = ')';
			recurArrange(ret, s, n, l, r + 1);
		}
		else						// the number of left parentheses we have arranged < the number of right parentheses, which is impossible
		{
			;
		}
		return;
	}
	vector<string> generateParenthesis(int n)
	{
		vector<string> ret;
		string s;
		s.resize(2 * n);
		recurArrange(ret, s, n, 0, 0);		// arrange parentheses from empty
		return ret;
	}
};
