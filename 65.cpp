#include <bits/stdc++.h>

#define ISDIGIT(ch) ((ch) >= '0' && (ch) <= '9')
#define ISDIGIT1TO9(ch) ((ch) >= '1' && (ch) <= '9')
#define ISWHITESPACE(ch) ((ch) == ' ' || (ch) == '\t' || (ch) == '\n' || (ch) == '\r')

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
	// This function determines whether a string can be interpreted as a decimal number
	// The main idea is sequentially scan every character and skip normal parts
	bool isNumber(string s)
	{
		int len = (int) s.size(), p = 0;
		// skip leading whitespaces
		while (len > 0 && ISWHITESPACE(s[len - 1]))
			--len;
		// skip trailing whitespaces
		while (p < len && ISWHITESPACE(s[p]))
			++p;
		if (p < len && (s[p] == '+' || s[p] == '-'))	// sign
			++p;
		if (p == len)															// error case: no digit
			return false;
		if (p < len && !ISDIGIT(s[p]) && s[p] != '.')							// error case: starting with characters other than digits or decimal points
			return false;
		bool decimal_point = (s[p] == '.');		// the flag of whether the number starts with decimal point; true means that there are no digit before decimal point
		while (p < len && ISDIGIT(s[p]))				// skip digits
			++p;
		if (p < len && s[p] == '.')						// if there is decimal point
		{
			++p;
			if (decimal_point && (p == len || (p < len && !ISDIGIT(s[p]))))		// error case: "." or ".E" or ".e"
				return false;
			if ((p < len && !ISDIGIT(s[p]) && s[p] != 'e' && s[p] != 'E'))		// error case: after decimal point there are characters other than digits or "E" or "e"
				return false;
			while (p < len && ISDIGIT(s[p]))			// skip digits
				++p;
		}
		if (p < len && (s[p] == 'E' || s[p] == 'e'))	// if there is exponents
		{
			++p;
			if (p < len && (s[p] == '+' || s[p] == '-'))
				++p;
			if (p == len || (p < len && !ISDIGIT(s[p])))						// error case: "10E" or "10E+"
				return false;
			while (p < len && ISDIGIT(s[p]))			// skip digits
				++p;
		}
		if (p < len)															// error case: there are other characters after a decimal number
			return false;
		return true;
	}
};
