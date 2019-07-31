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
	int maxProduct(vector<int>& nums)
	{
		int ret = INT_MIN;
		for (int i = 0; i < nums.size(); ++i)
		{
			int product = 1;
			for (int j = i; j < nums.size(); ++j)
			{
				product *= nums[j];
				ret = max(ret, product);
			}
		}
		return ret;
	}
};
