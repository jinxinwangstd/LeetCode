#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	string convert(string s, int numRows)
	{
		if (s.empty())		// corner case: input string is empty string
			return string();
		// There is a repeated pattern in the zigzag arrangement, which are the vertical line and diagonal line
		int num = numRows > 2 ? 2 * (numRows - 1) : numRows;	// number of characters in a repeated pattern
		int num_set = (s.size() / num) + (s.size() % num > 0);	// number of repeated pattern
		string ret;
		for (int i = 0; i != numRows; ++i)			// output the repeated pattern line by line
		{
			for (int j = 0; j != num_set; ++j)		// for the same line
			{
				if (i == 0 || i == numRows - 1)		// in each pattern, the first line and last line contains only one character
				{
					if (i + j * num < s.size())
						ret.push_back(s[i + j * num]);
				}
				else								// in each pattern, the other line contains two characters
				{
					if (i + j * num < s.size())			// left character
						ret.push_back(s[i + j * num]);
					if ((num - i) + j * num < s.size())	// right character
						ret.push_back(s[(num - i) + j * num]);
				}
			}
		}
		return ret;
	}
};
