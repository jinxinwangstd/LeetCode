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
	int findPeakElement(vector<int>& nums)
	{
		int num = nums.size();
		int lo = 0, hi = num - 1;
		int mid;
		while (lo < hi)
		{
			mid = (lo + hi) / 2;
			if (mid < num && nums[mid] > nums[mid + 1])
			{
				hi = mid;
			}
			else
			{
				lo = mid + 1;	// why add 1
			}
		}
		mid = (lo + hi) / 2;
		return mid;
	}
};
