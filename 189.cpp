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
	void rotate(vector<int>& nums, int k)
	{
		int size = (int)nums.size();
		k %= size;
		// reverse all vector elements
		for (int i = 0; i < (size + 1) / 2; ++i)
			swap(nums[i], nums[size - 1 - i]);
		int l_size = k, r_size = size - k;
		// reverse left part elements
		for (int i = 0; i < (l_size + 1) / 2; ++i)
			swap(nums[i], nums[l_size - 1 - i]);
		// reverse right part elements
		for (int i = 0; i < (r_size + 1) / 2; ++i)
			swap(nums[l_size + i], nums[l_size + r_size - 1 - i]);
		return;
	}
};
