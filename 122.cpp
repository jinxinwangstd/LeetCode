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
	int maxProfit(vector<int>& prices)
	{
		int ret = 0;
		for (int i = 1; i < prices.size(); ++i)
		{
			if (prices[i] > prices[i - 1])
				ret += (prices[i] - prices[i - 1]);
		}
		return ret;
	}
};
