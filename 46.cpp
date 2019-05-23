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
	set<int> record;	// the set containing elements already in the permutation to avoid duplicate elements
	void generatePermutation(vector<vi>& ret, vi& nums, vi& permutation, int start)
	{
		if (start == (int) nums.size())		// the permutation has enough length
		{
			ret.push_back(permutation);
			return;
		}
		// Try all possible elements
		for (int i = 0; i != (int) nums.size(); ++i)
		{
			if (!record.count(nums[i]))
			{
				record.insert(nums[i]);		// record the element we chose
				permutation[start] = nums[i];	// use that element
				generatePermutation(ret, nums, permutation, start + 1);		// move up to the next element
				record.erase(nums[i]);		// recover context
			}
		}
		return;
	}
	vector< vector<int> > permute(vector<int>& nums)
	{
		vector<vi> ret;
		vi permutation(nums.size());
		generatePermutation(ret, nums, permutation, 0);
		return ret;
	}
};
