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
	int rob(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		int n = (int)nums.size();
		vi memo(n + 1);
		memo[n] = 0;
		memo[n - 1] = nums[n - 1];
		for (int i = n - 2; i >= 0; --i)
		{
			memo[i] = max(memo[i + 1], nums[i] + memo[i + 2]);
		}
		return memo[0];
	}
};
