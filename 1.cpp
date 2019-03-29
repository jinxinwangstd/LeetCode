#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

// Reverse indexing
vector<int> twoSum(vector<int>& nums, int target)
{
	map<int, int> pos;
	vector<int> ret;
	int size = nums.size();
	for (int i = 0; i != size; ++i)
		pos[nums[i]] = i;
	for (int i = 0; i != size; ++i)
	{
		int rest = target - nums[i];
		if (pos.count(rest) && pos[rest] != i)
		{
			ret.push_back(i);
			ret.push_back(pos[rest]);
			return ret;
		}
	}
	return ret;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	return 0;
}
