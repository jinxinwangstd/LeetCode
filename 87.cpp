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
	const int count_size = 256;
	vector< vector<vi> > memo;
	// This function determines whether two strings are scramble strings based on dynamic programming algorithms
	int determineScramble(const string& s1, const string& s2, int p1, int p2, int len)
	{
		if (memo[len][p1][p2] != -1)		// visited state
			return memo[len][p1][p2];
		vi count(count_size, 0);
		int i = 0;
		bool same = true;
		while (i < len)
		{
			count[s1[p1 + i] - 'a']++;
			count[s2[p2 + i] - 'a']--;
			if (same)
				same = s1[p1 + i] == s2[p2 + i];
			i++;
		}
		for (int i = 0; i != count_size; ++i)	// pruning: string with different character composition
			if (count[i])
				return memo[len][p1][p2] = 0;
		if (same)								// pruning: same string
			return memo[len][p1][p2] = 1;
		int ret = 0;
		for (int i = 1; i < len; ++i)
		{
			// scramble case one: two substrings weren't swapped
			if (determineScramble(s1, s2, p1, p2, i) && determineScramble(s1, s2, p1 + i, p2 + i, len - i))
			{
				ret = 1;
				break;
			}
			// scramble case two: two substrings were swapped
			if (determineScramble(s1, s2, p1, p2 + len - i, i) && determineScramble(s1, s2, p1 + i, p2, len - i))
			{
				ret = 1;
				break;
			}
		}
		return memo[len][p1][p2] = ret;
	}
	bool isScramble(string s1, string s2)
	{
		vi elem(s1.size(), -1);
		vector<vi> row(s1.size(), elem);
		memo.assign(s1.size() + 1, row);
		int ret = determineScramble(s1, s2, 0, 0, s1.size());
		return ret == 1;
	}
};
