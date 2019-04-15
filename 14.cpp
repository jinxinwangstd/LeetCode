#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
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
			if (i == (int) strs[0].size())
				return ret;
			c = strs[0][i];
			for (int j = 1; j != num; ++j)
			{
				if (i == (int) strs[j].size())
					return ret;
				if (strs[j][i] != c)
					return ret;
			}
			ret.push_back(c);
			++i;
		}
	}
};
