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
	set<int> record;		// record the index of elements we have chosen
	void generatePermutation(vector<vi>& ret, vi& nums, vi& permutation, int start)
	{
		if (start == (int) nums.size())		// the permutation has enough length
		{
			ret.push_back(permutation);
			return;
		}
		int last_element = INT_MAX;		// the last element we have chosen at the same position to avoid duplicate permutations
		// Try all possible elements
		for (int i = 0; i != (int) nums.size(); ++i)
		{
			if (!record.count(i) && last_element != nums[i])	// the elements we choose must not be in the permutation and not same as the last element we chose
			{
				record.insert(i);
				permutation[start] = nums[i];		// use that element
				last_element = nums[i];
				generatePermutation(ret, nums, permutation, start + 1);		// move up to the next position
				record.erase(i);			// recover the context
			}
		}
		return;
	}
	vector< vector<int> > permuteUnique(vector<int>& nums)
	{
		vector<vi> ret;
		vi permutation(nums.size());
		sort(nums.begin(), nums.end());			// to make the same elements near to each other
		generatePermutation(ret, nums, permutation, 0);
		return ret;
	}
};
