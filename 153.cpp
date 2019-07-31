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
	int findMin(vector<int>& nums)
	{
		int num = nums.size();
		if (num < 2)
			return nums[0];
		if (nums[0] < nums[num - 1])
			return nums[0];
		int lo = 0, hi = num - 1;
		int mid;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (nums[mid] > nums[mid + 1])
				return nums[mid + 1];
			if (nums[mid] > nums[lo])
			{
				lo = mid;
			}
			else
			{
				hi = mid;
			}
		}
		return nums[mid + 1];
	}
};
