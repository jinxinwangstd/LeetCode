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
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
	{
		int num = nums.size();
		vector<string> ret;
		if (nums.empty())
		{
			ret.push_back(lower == upper ? to_string(lower) : to_string(lower) + "->" + to_string(upper));
			return ret;
		}
		// calculate the missing elements in the left end
		ll l = 0, r = 0;
		if ((ll)lower < (ll)nums[0])
		{
			l = lower;
			r = nums[0] - 1;
			ret.push_back(l == r ? to_string(l) : to_string(l) + "->" + to_string(r));
		}
		for (int i = 0; i < num - 1; ++i)
		{
			if ((ll)nums[i] < (ll)nums[i + 1] - 1)
			{
				l = nums[i] + 1;
				r = nums[i + 1] - 1;
				ret.push_back(l == r ? to_string(l) : to_string(l) + "->" + to_string(r));
			}
		}
		// calculate the missing elements in the right end
		if ((ll)nums[num - 1] < (ll)upper)
		{
			l = nums[num - 1] + 1;
			r = upper;
			ret.push_back(l == r ? to_string(l) : to_string(l) + "->" + to_string(r));
		}
		return ret;
	}
};
