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
	vector< vector<vi> > memo;
	// This function gradually matches characters in s3 with characters in s1 or in s2
	// The basic idea is backtracking
	bool matchSubstring(const string& s1, const string& s2, const string& s3, int cur1, int cur2, int cur3)
	{

		if (cur3 == -1)			// base case: when we consume characters in s3, whether the characters in s1 and s2 are consumed
			return cur1 == -1 && cur2 == -1;
		// try to match characters in s3 with the ones in s1 and s2
		char c1 = cur1 >= 0 ? s1[cur1] : '\0';
		char c2 = cur2 >= 0 ? s2[cur2] : '\0';
		char c3 = s3[cur3];
		bool ret = false;
		if (c1 == c3)
			ret = ret || matchSubstring(s1, s2, s3, cur1 - 1, cur2, cur3 - 1);
		if (c2 == c3)
			ret = ret || matchSubstring(s1, s2, s3, cur1, cur2 - 1, cur3 - 1);
		return ret;
	}
	bool isInterleave(string s1, string s2, string s3)
	{
		return matchSubstring(s1, s2, s3, s1.size() - 1, s2.size() - 1, s3.size() - 1);
	}
};
