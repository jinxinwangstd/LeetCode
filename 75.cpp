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
	// This function sort a vector with three different numbers into ascending order
	void sortColors(vector<int>& nums)
	{
		int n = (int) nums.size();
		// we use two pointers to record the positions of next smallest element ("0") and next biggest element ("2")
		int zero_pos = 0, two_pos = n - 1;
		// update the two pointers
		while (zero_pos < n && nums[zero_pos] == 0)
			++zero_pos;
		while (two_pos >= 0 && nums[two_pos] == 2)
			--two_pos;
		int i = zero_pos;
		// Scan all elements in middle, and the basic idea is to exchange "0" with the element pointed by zero_pos, and exchange "2" with the element pointed by two_pos
		while (i <= two_pos)
		{
			if (nums[i] == 0)			// handle smallest element met
			{
				if (i == zero_pos)
					++i;
				else  			// exchange
				{
					int temp = nums[zero_pos];
					nums[zero_pos] = nums[i];
					nums[i] = temp;
				}
				++zero_pos;		// update pointer to the next non-smallest element
			}
			else if (nums[i] == 2)		// handle biggest element met
			{
				if (i == two_pos)
					++i;
				else 			// exchange
				{
					int temp = nums[two_pos];
					nums[two_pos] = nums[i];
					nums[i] = temp;
				}
				--two_pos;		// update pointer to the next non-biggest element
			}
			else
				++i;
		}
		return;
	}
};
