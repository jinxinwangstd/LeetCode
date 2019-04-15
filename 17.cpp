#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	string mappings[9] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	void arrange(vector<string>& ret, string& s, const string& digits, int index)
	{
		if (index == (int) digits.size())
		{
			ret.push_back(s);
			return;
		}
		int digit = digits[index] - '0';
		for (int i = 0; i != mappings[digit - 1].size(); ++i)
		{
			s[index] = mappings[digit - 1][i];
			arrange(ret, s, digits, index + 1);
		}
		return;
	}
	vector<string> letterCombinations(string digits)
	{
		vector<string> ret;
		if (!digits.size())
			return ret;
		string s;
		s.resize(digits.size());
		arrange(ret, s, digits, 0);
		return ret;
	}
};
