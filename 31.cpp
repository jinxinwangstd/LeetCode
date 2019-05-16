#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	void nextPermutation(vector<int>& nums)
	{
		int descend_len = 1, len = nums.size();
		// Find the non-increasing sequence starting from the end
		while (descend_len < len && nums[len - descend_len] <= nums[len - descend_len - 1])
			descend_len++;
		// Sort them
		sort(nums.end() - descend_len, nums.end());
		if (descend_len == len)
			return;
		// We need to swap the pivot element other than the non-increasing sequence with its upper bound in the sequence
		vector<int>::iterator pivot_iter = nums.end() - descend_len - 1;
		vector<int>::iterator upper_iter = upper_bound(nums.end() - descend_len, nums.end(), *pivot_iter);
		swap(*pivot_iter, *upper_iter);
		return;
	}
};
