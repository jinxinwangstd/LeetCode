#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	string mappings[9] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	// This function arrange the index-th digit in the string "digits"
	void arrange(vector<string>& ret, string& s, const string& digits, int index)
	{
		if (index == (int) digits.size())	// we have arranged all digits, then just append the resulting string to the vector
		{
			ret.push_back(s);
			return;
		}
		int digit = digits[index] - '0';	// the value of the digit we need to arrange a corresponding letter
		for (int i = 0; i != mappings[digit - 1].size(); ++i)	// enumerate all valid letters
		{
			s[index] = mappings[digit - 1][i];
			arrange(ret, s, digits, index + 1);		// recursively arrange the rest digits
		}
		return;
	}
	vector<string> letterCombinations(string digits)
	{
		vector<string> ret;
		if (!digits.size())				// corner case: digits are empty
			return ret;
		string s;						// string for letter combinations
		s.resize(digits.size());		// reserve spaces for arranged letters
		arrange(ret, s, digits, 0);		// arrange letter combinations starting from the first digit
		return ret;
	}
};
