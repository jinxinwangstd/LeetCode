#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	// Find the position of the smallest element, i.e. the pivot
	int findPivotPos(vector<int>& nums, int first, int last)
	{
		int lo = first, hi = last;
		int pivot;
		if (nums[lo] < nums[hi])	// ascending sequence
			return 0;
		// binary search the biggest element, and then return the next one, which is the smallest one
		while (lo <= hi)
		{
			pivot = (lo + hi) / 2;
			if (nums[pivot] > nums[pivot + 1])	// pivot is the biggest element
				return pivot + 1;
			if (nums[pivot] < nums[lo])		// we need to compare with the lower bound cause the lower bound is at least the biggest element
				hi = pivot - 1;
			else
				lo = pivot + 1;
		}
		return pivot;
	}
	// Binary search the target in an ascending sequence; if not found, return -1
	int binarySearch(vector<int>& nums, int first, int last, int target)
	{
		int lo = first, hi = last;
		int mid;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (nums[mid] == target)
				return mid;
			if (target > nums[mid])
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		return -1;

	}
	int search(vector<int>& nums, int target)
	{
		if (nums.empty())
			return -1;
		if (nums.size() == 1)
			return nums[0] == target ? 0 : -1;
		int len = (int) nums.size();
		int pivot_pos = findPivotPos(nums, 0, len - 1);
		int ret = -1;
		if (!pivot_pos)		// pivot position is 0, which means that the sequence is ascending
			ret = binarySearch(nums, 0, len - 1, target);
		else				// find the part which the target belongs to
		{
			if (target >= nums[0])
				ret = binarySearch(nums, 0, pivot_pos - 1, target);
			else
				ret = binarySearch(nums, pivot_pos, len - 1, target);
		}
		return ret;
	}
};
