#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	// Linear scan to transfer Roman string to integer
	int romanToInt(string s)
	{
		int ret = 0, num = (int) s.size();
		int i = 0;
		while (i != num)
		{
			switch (s[i])		// different base numbers
			{
			case 'M':			// M: 1000
				ret += 1000;
				break;
			case 'D':			// D: 500
				ret += 500;
				break;
			case 'C':
				if (i + 1 != num && s[i + 1] == 'M')		// CM: 900
				{
					ret += 900;
					++i;	// base number corresponds to two characters so we need one extra pointer advance
				}
				else if (i + 1 != num && s[i + 1] == 'D')	// CD: 400
				{
					ret += 400;
					++i;	// base number corresponds to two characters so we need one extra pointer advance
				}
				else			// C: 100
					ret += 100;
				break;
			case 'L':			// L: 50
				ret += 50;
				break;
			case 'X':
				if (i + 1 != num && s[i + 1] == 'C')		// XC: 90
				{
					ret += 90;
					++i;	// base number corresponds to two characters so we need one extra pointer advance
				}
				else if (i + 1 != num && s[i + 1] == 'L')	// XL: 40
				{
					ret += 40;
					++i;	// base number corresponds to two characters so we need one extra pointer advance
				}
				else			// X: 10
					ret += 10;
				break;
			case 'V':			// V: 5
				ret += 5;
				break;
			case 'I':
				if (i + 1 != num && s[i + 1] == 'X')		// IX: 9
				{
					ret += 9;
					++i;	// base number corresponds to two characters so we need one extra pointer advance
				}
				else if (i + 1 != num && s[i + 1] == 'V')	// IV: 4
				{
					ret += 4;
					++i;	// base number corresponds to two characters so we need one extra pointer advance
				}
				else			// I: 1
					ret += 1;
				break;
			}
			++i;	// pointer advance
		}
		return ret;
	}
};
