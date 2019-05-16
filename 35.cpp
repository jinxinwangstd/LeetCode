#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		// binary search to find the target in the ascending sequence
		int lo = 0, hi = (int) nums.size() - 1;
		int mid = -1;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (nums[mid] == target)		// found the target
				return mid;
			else if (nums[mid] < target)
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		// not found the target, we need to check whether the position is pointed to its smaller neighbor or bigger neighbor
		if (nums[mid] < target)			// ensure the position is pointed to its bigger neighbor
			++mid;
		return mid;
	}
};
