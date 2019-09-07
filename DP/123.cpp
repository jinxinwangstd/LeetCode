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
		int states[2][4] = {INT_MIN, 0, INT_MIN, 0};
		int len = prices.size(), cur = 0, next = 1;
		for (int i = 0; i < len; ++i)
		{
			states[next][0] = max(states[cur][0], -prices[i]);
			states[next][1] = max(states[cur][1], states[cur][0] + prices[i]);
			states[next][2] = max(states[cur][2], states[cur][1] - prices[i]);
			states[next][3] = max(states[cur][3], states[cur][2] + prices[i]);
			swap(next, cur);
		}
		return max(states[cur][1], states[cur][3]);
	}
};
