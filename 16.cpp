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
				// We have chosen the first two numbers by enumerations
				int rest = target - nums[i] - nums[j];
				int r, d;			// r is the closest value to the rest and d is the difference between r and rest
				int k = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), rest));	// the index of the third element
				if (k <= j)			// repeated three sum
					continue;
				if (k == num)							// choose nums[k-1] (nearest element < "rest") because all elements are smaller than "rest"
					r = nums[num - 1];
				else if (nums[k] == rest || k == 0)		// choose nums[k] (nearest element >= "rest") because it equals exactly "rest"
					r = nums[k];
				else 									// choose between nums[k-1] (nearest element < "rest") and nums[k-1] (nearest element > "rest")
					r = abs(rest - nums[k]) > abs(rest - nums[k - 1]) ? nums[k - 1] : nums[k];
				d = abs(rest - r);		// calculate the difference
				if (d < difference)		// update the closest three sum
				{
					ret = r + nums[i] + nums[j];
					difference = d;
				}
			}
		}
		return ret;
	}
};
