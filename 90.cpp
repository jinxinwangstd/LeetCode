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
	// This function generates subsets containing k elements based on backtracking algorithms
	void generateKSubsets(vector<vi>& ret, const vi& nums, vi& subset, int p1, int p2)
	{
		if (p1 == (int) subset.size())		// base case: we generate a valid subset with k elements
		{
			ret.push_back(subset);
			return;
		}
		// try every possible elements
		for (int i = p2; i < nums.size(); ++i)
		{
			subset[p1] = nums[i];
			generateKSubsets(ret, nums, subset, p1 + 1, i + 1);
			while (i + 1 < nums.size() && nums[i + 1] == nums[i])	// move to the next different element
				++i;
		}
		return;
	}
	vector< vector<int> > subsetsWithDup(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());		// the required step to avoid duplicates
		vector<vi> ret;
		vi subset;
		// generate subset with different sizes
		for (int i = 0; i <= nums.size(); ++i)
		{
			subset.resize(i);
			generateKSubsets(ret, nums, subset, 0, 0);
		}
		return ret;
	}
};
