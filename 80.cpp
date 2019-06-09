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
	// This function removes the duplicates in-place such that duplicates appeared at most twice in a sorted array
	int removeDuplicates(vector<int>& nums)
	{
		int cur = INT_MIN, num = 0;
		// we maintain two pointers, one is the next position to copy elements to, another is the next position to scan
		int scan_pos = 0, copy_pos = 0;
		int n = (int) nums.size();
		while (scan_pos < n)
		{
			if (nums[scan_pos] != cur)		// met a new element
			{
				cur = nums[scan_pos];
				num = 1;
				nums[copy_pos++] = cur;
			}
			else 							// met a duplicates
			{
				++num;
				if (num <= 2)		// copy the first two duplicates
					nums[copy_pos++] = cur;
			}
			++scan_pos;						// move forward to the next element
		}
		return copy_pos;
	}
};
