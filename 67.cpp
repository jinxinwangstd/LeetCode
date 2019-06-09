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
	// This function
	string addBinary(string a, string b)
	{
		int a_len = (int) a.size(), b_len = (int) b.size();
		int ret_len = max(a_len, b_len) + 1;		// the max possible length of the result is the length of the longer number plus one
		string ret;
		ret.resize(ret_len);
		int sum = 0, carry = 0;
		for (int i = 0; i != ret_len; ++i)
		{
			// fetch two adding digits
			int a_i = a_len - 1 - i, b_i = b_len - 1 - i;
			int a_num = a_i >= 0 ? a[a_i] - '0' : 0;
			int b_num = b_i >= 0 ? b[b_i] - '0' : 0;
			// perform one-bit adder
			sum = a_num + b_num + carry;
			ret[ret_len - 1 - i] = sum % 2 + '0';
			carry = sum / 2;
		}
		if (ret[0] == '0')		// if the highest digit is 0, erase the highest digit
			ret.erase(ret.begin());
		return ret;
	}
};
