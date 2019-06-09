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
	// This function calculate the length of the last word in a string
	int lengthOfLastWord(string s)
	{
		int ret = 0;
		int i = (int) s.size() - 1;
		// find the last character of the last word
		while (i >= 0 && !isalpha(s[i]))
			--i;
		// no alphabet in the string then there is no word
		if (i < 0)
			return ret;
		// start counting from the last character backwards until we reach a non-alphabet
		while (i >= 0 && isalpha(s[i]))
		{
			++ret;
			--i;
		}
		return ret;
	}
};
