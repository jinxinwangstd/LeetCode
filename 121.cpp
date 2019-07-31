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
		int size = prices.size();
		vi buys(size, INT_MAX);
		for (int i = 1; i < size; ++i)
			buys[i] = min(prices[i - 1], buys[i - 1]);
		int ret = 0;
		for (int i = 0; i < size; ++i)
			ret = max(ret, prices[i] - buys[i]);
		return ret > 0 ? ret : 0;
	}
};
