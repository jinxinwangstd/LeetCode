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
	string reverseWords(string s)
	{
		string ret;
		int len = s.size();
		int word_len = 0;
		for (int i = len - 1; i >= 0; --i)
		{
			if (s[i] == ' ')
			{
				word_len = 0;
			}
			else
			{
				word_len++;
				if (i - 1 < 0 || s[i - 1] == ' ')
				{
					if (!ret.empty())
						ret += " ";
					ret += s.substr(i, word_len);
				}
			}
		}
		return ret;
	}
};
