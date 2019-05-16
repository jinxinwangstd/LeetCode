#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	// Binary search the target in an ascending sequence; if not found, return -1
	int binarySearch(vector<int>& nums, int begin, int end, int target)
	{
		int lo = begin, hi = end;
		int mid;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		return -1;
	}
	// Binary search the target in an ascending sequence; if not found; return the position of near element
	int lowerSearch(vector<int>& nums, int begin, int end, double target)
	{
		int lo = begin, hi = end;
		int mid;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		return mid;		// the mid may be the left or right adjacent element to the target
	}
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> ret;
		// Check whether the target appeared in the sequence
		int occurrence = binarySearch(nums, 0, nums.size() - 1, target);
		if (occurrence == -1)		// not appeared
		{
			ret.push_back(-1);
			ret.push_back(-1);
		}
		else						// appeared
		{
			// Use target - 0.5 to find the position of the first target element or its former element
			int start = lowerSearch(nums, 0, nums.size() - 1, target - 0.5);
			if (nums[start] != target)
				++start;
			// Use target + 0.5 to find the position of the last target element or its next element
			int end = lowerSearch(nums, 0, nums.size() - 1, target + 0.5);
			if (nums[end] != target)
				--end;
			ret.push_back(start);
			ret.push_back(end);
		}
		return ret;
	}
};
