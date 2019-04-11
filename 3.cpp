#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		map<char, int> m;	// characters and their positions in current substring without repeated characters
		int num = (int) s.size(), ret = 0, start = 0;	// start is the start position of current substring
		for (int i = 0; i != num; ++i)
		{
			if (m.count(s[i]))		// repeated characters
			{
				ret = max(ret, i - start);	// compare and record the length
				for (int j = start; j < m[s[i]]; ++j)	// erase all characters not in the next substring
					m.erase(s[j]);
				start = m[s[i]] + 1;		// next substring starts at the next character of repeated character
				m[s[i]] = i;				// update the position of the repeated character
			}
			else
				m[s[i]] = i;		// add new character
		}
		ret = max(ret, num - start);	// the last substring may not be compared and record
		return ret;
	}
};
