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
	int threeSumClosest(vector<int>& nums, int target)
	{
		int ret = 0, difference = INT_MAX;
		sort(nums.begin(), nums.end());
		int num = (int) nums.size();
		for (int i = 0; i != num; ++i)
		{
			for (int j = i + 1; j != num; ++j)
			{
				int rest = target - nums[i] - nums[j];
				int r, d;
				int k = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), rest));
				if (k <= j)
					continue;
				if (k == num)
					r = nums[num - 1];
				else if (nums[k] == rest || k == 0)
					r = nums[k];
				else
					r = abs(rest - nums[k]) > abs(rest - nums[k - 1]) ? nums[k - 1] : nums[k];
				d = abs(rest - r);
				if (d < difference)
				{
					ret = r + nums[i] + nums[j];
					difference = d;
				}
			}
		}
		return ret;
	}
};
