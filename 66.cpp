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
	// This function return the vector representing an integer after plus it with one
	vector<int> plusOne(vector<int>& digits)
	{
		int num_digits = (int) digits.size();
		// Use carry = 1 to realize plus one
		int carry = 1, sum = 0;		// sum is the original sum for each digit
		for (int i = num_digits - 1; i >= 0; --i)
		{
			if (!carry)			// no carry means the higher digits are the same
				break;
			// perform one-bit adder
			sum = digits[i] + carry;
			digits[i] = sum % 10;
			carry = sum / 10;
		}
		if (carry)			// add one highest digit
			digits.insert(digits.begin(), carry);
		return digits;
	}
};
