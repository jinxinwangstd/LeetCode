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
	// Reverse indexing
	vector<int> twoSum(vector<int>& nums, int target)
	{
		map<int, int> pos;
		vector<int> ret;
		int size = nums.size();
		for (int i = 0; i != size; ++i)		// construct the reverse indexing
			pos[nums[i]] = i;
		for (int i = 0; i != size; ++i)
		{
			int rest = target - nums[i];		// calculate the other adder
			if (pos.count(rest) && pos[rest] != i)	// the other number should be in the list and cannot be itself
			{
				ret.push_back(i);
				ret.push_back(pos[rest]);
				return ret;
			}
		}
		return ret;
	}
};
