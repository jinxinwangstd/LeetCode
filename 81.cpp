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
	// Find the position of the smallest element, i.e. the pivot using linear search
	int findPivotPos(vi& nums)
	{
		int pivot = 0;
		while (pivot + 1 < (int) nums.size() && nums[pivot] <= nums[pivot + 1])
			++pivot;
		return pivot + 1;
	}
	// This function determines whether a target can be searched in an ordered sequence using binary search
	bool binarySearch(vi& nums, int first, int last, int target)
	{
		int lo = first, hi = last;
		int mid;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (nums[mid] > target)
				hi = mid - 1;
			else if (nums[mid] < target)
				lo = mid + 1;
			else
				return true;
		}
		return nums[mid] == target;
	}
	// This function determines whether we can find the target value in a rotated array which may contain duplicates
	// The basic idea is finding two ordered part and using binary search respectively
	bool search(vector<int>& nums, int target)
	{
		if (nums.empty())
			return false;
		int pivot = findPivotPos(nums);
		bool ret = binarySearch(nums, 0, pivot - 1, target);
		if (pivot < nums.size() && !ret)
			ret = binarySearch(nums, pivot, nums.size() - 1, target);
		return ret;
	}
};
