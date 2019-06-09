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
	// This function finds the closest 3-sum set to the target based on a greedy algorithm
	int threeSumClosest(vector<int>& nums, int target)
	{
		sort(nums.begin(), nums.end());		// necessary operation to avoid duplicate 3-sum or duplicate elements in a 3-sum
		int ret = nums[0] + nums[1] + nums[2];
		int n = (int) nums.size();
		// For 3-sums with the same first element, find the closest set
		for (int i = 0; i < n; ++i)
		{
			int j = i + 1, k = n - 1;
			while (j < k)
			{
				int sum = nums[i] + nums[j] + nums[k];
				if (abs(sum - target) < abs(ret - target))
					ret = sum;
				// gradually make it closer to target
				if (sum < target)			// too small
					++j;
				else if (sum > target)		// too large
					--k;
				else 						// sum == target
					return sum;
			}
		}
		return ret;
	}
};
