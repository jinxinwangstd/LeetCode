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
	string fractionToDecimal(int numerator, int denominator)
	{
		if (!numerator)
			return "0";
		bool neg = (numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0);
		ll num = abs((ll)numerator);
		ll denom = abs((ll)denominator);
		map<int, int> res_record;
		ll integral = num / denom;
		ll res = num % denom;
		string ret;
		while (res && !res_record.count(res))
		{
			res_record[res] = ret.size();
			res *= 10;
			ret += to_string(res / denom);
			res = res % denom;
		}
		if (res)
		{
			ret = to_string(integral) + "." + ret.substr(0, res_record[res]) + "(" + ret.substr(res_record[res]) + ")";
		}
		else
		{
			if (res_record.empty())
				ret = to_string(integral);
			else
				ret = to_string(integral) + "." + ret;
		}
		if (neg)
			ret = "-" + ret;
		return ret;
	}
};
