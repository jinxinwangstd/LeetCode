#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	// Synchronously linear scan each string and select the common first n characters
	string longestCommonPrefix(vector<string>& strs)
	{
		int num = (int) strs.size();
		char c;
		string ret;
		if (!num)
			return ret;
		int i = 0;
		while (true)
		{
			if (i == (int) strs[0].size())		// reach the end of the first string
				return ret;
			c = strs[0][i];						// the character we need to scan at this iteration
			for (int j = 1; j != num; ++j)
			{
				if (i == (int) strs[j].size())	// reach the end of one string
					return ret;
				if (strs[j][i] != c)			// not common in all strings, then return all characters before it
					return ret;
			}
			ret.push_back(c);
			++i;
		}
	}
};
