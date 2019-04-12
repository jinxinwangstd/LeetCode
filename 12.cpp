#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	string intToRoman(int num)
	{
		map<int, string> romans;
		romans[1000] = "M";
		romans[900] = "CM";
		romans[500] = "D";
		romans[400] = "CD";
		romans[100] = "C";
		romans[90] = "XC";
		romans[50] = "L";
		romans[40] = "XL";
		romans[10] = "X";
		romans[9] = "IX";
		romans[5] = "V";
		romans[4] = "IV";
		romans[1] = "I";
		string ret;
		// go through base numbers in decreasing order, and calculate the corresponding digits
		for (int i = 0; i != 13; ++i)
		{
			int times = num / nums[i];
			while (times--)
				ret.append(romans[nums[i]]);
			num %= nums[i];
		}
		return ret;
	}
};
