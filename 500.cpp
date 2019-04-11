#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	const string rows[3] = {string("qwertyuiop"), string("asdfghjkl"), string("zxcvbnm")};
	vector<string> findWords(vector<string>& words)
	{
		vector<string> ret;
		int num = (int) words.size();
		for (int i = 0; i != num; ++i)
		{
			string s = words[i];
			if (!s.size())
				ret.push_back(s);
			int row_i = 0;
			for (int j = 0; j != 3; ++j)
				if (find(rows[j].begin(), rows[j].end(), tolower(s[0])) != rows[j].end())
				{
					row_i = j;
					break;
				}
			bool valid = true;
			for (int j = 1; j != (int) s.size(); ++j)
			{
				if (find(rows[row_i].begin(), rows[row_i].end(), tolower(s[j])) == rows[row_i].end())
				{
					valid = false;
					break;
				}
			}
			if (valid)
				ret.push_back(s);
		}
		return ret;
	}
};
