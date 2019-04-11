#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	bool isNumeric(char c)
	{
		return c >= '0' && c <= '9';
	}
	int myAtoi(string str)
	{
		size_t i = 0;
		ll ret = 0;
		// find the first valid character
		i = str.find_first_not_of(' ');
		if (i == string::npos || !(str[i] == '+' || str[i] == '-' || isNumeric(str[i])))
			return ret;
		// remember sign digit
		bool neg = false;
		if (str[i] == '+' || str[i] == '-')
		{
			neg = (str[i] == '-');
			++i;
		}
		// append every digit
		while (i != str.size() && isNumeric(str[i]))
		{
			// Check whether intermediate result is integer overflow to avoid larger result than 64 bits
			if (ret > INT_MAX)
				return neg ? INT_MIN : INT_MAX;
			ret *= 10;
			ret += str[i] - '0';
			++i;
		}
		ret = neg ? -ret : ret;
		// Check whether result is integer overflow
		if (ret < INT_MIN)
			return INT_MIN;
		if (ret > INT_MAX)
			return INT_MAX;
		return ret;
	}
};
