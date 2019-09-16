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
	int maxProfit(int k, vector<int>& prices)
	{
		int n = (int)prices.size(), ret = 0, v, p = 0;
		priority_queue<int> profits;
		stack<ii> vp_pairs;
		while (p < n)
		{
			for (v = p; v < n - 1 && prices[v] >= prices[v + 1]; ++v)
				;
			for (p = v + 1; p < n && prices[p] >= prices[p - 1]; ++p)
				;
			// if current v is lower than the last v, save last v/p pair
			while (!vp_pairs.empty() && prices[v] < prices[vp_pairs.top().first])
			{
				profits.push(prices[vp_pairs.top().second] - prices[vp_pairs.top().first]);
				vp_pairs.pop();
			}
			// if current v is higher than the last v and the current p is higher than the last p
			while (!vp_pairs.empty() && prices[p - 1] >= prices[vp_pairs.top().second])
			{
				profits.push(prices[vp_pairs.top().second] - prices[v]);
				v = vp_pairs.top().first;
				vp_pairs.pop();
			}
			// other kind of v/p pairs are pushed into stack
			vp_pairs.push(make_pair(v, p - 1));
		}
		// save profits of the rest v/p pairs
		while (!vp_pairs.empty())
		{
			profits.push(prices[vp_pairs.top().second] - prices[vp_pairs.top().first]);
			vp_pairs.pop();
		}
		// extract the highest k profits of v/p pairs and sum them up
		for (int i = 0; i < k && !profits.empty(); ++i)
		{
			ret += profits.top();
			profits.pop();
		}
		return ret;
	}
};
