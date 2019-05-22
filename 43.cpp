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
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0")			// corner case: one of the multiplier is 0
			return "0";
		string ret;
		int carry = 0, digit = 0;
		int len1 = (int) num1.size(), len2 = (int) num2.size();
		int len = (len1 - 1) + (len2 - 1) + 1;
		// For the following calculation, the index all starts from right, which means the right-most digit is 0-th digit
		for (int i = 0; i != len; ++i)
		{
			// calculate the ith digit of the result
			int sum = 0;
			// loop through all digits in num1 which can contribute to the ith digit of the result
			for (int i1 = 0; i1 < len1 && i1 <= i; ++i1)
			{
				if (i - i1 < len2)	// the corresponding bit in num2 is also valid
				{
					int i2 = i - i1;
					int digit1 = num1[len1 - 1 - i1] - '0', digit2 = num2[len2 - 1 - i2] - '0';		// find the two digits
					sum += digit1 * digit2;
				}
			}
			sum += carry;	// don't forget the carry from the last digit
			// record the result of this digit
			carry = sum / 10;
			digit = sum % 10;
			ret = to_string(digit) + ret;
		}
		if (carry)	// don't forget the carry from the highest digit calculation
			ret = to_string(carry) + ret;
		return ret;
	}
};
