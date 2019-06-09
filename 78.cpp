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
	// This function generates all subsets of a given length based on backtracking algorithms
	void generateKSubsets(vector<vi>& ret, vi& nums, vi& subset, int pos, int start)
	{
		if (pos == (int) subset.size())
		{
			ret.push_back(subset);
			return;
		}
		for (int i = start; i < nums.size(); ++i)
		{
			subset[pos] = nums[i];
			generateKSubsets(ret, nums, subset, pos + 1, i + 1);
		}
		return;
	}
	// This function generates all subsets of a set containing distinct numbers
	vector< vector<int> > subsets(vector<int>& nums)
	{
		vector<vi> ret;
		vi subset;
		for (int i = 0; i <= nums.size(); ++i)
		{
			subset.resize(i);
			generateKSubsets(ret, nums, subset, 0, 0);
		}
		return ret;
	}
};
