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
	int firstMissingPositive(vector<int>& nums)
	{
		if (nums.empty())		// corner case: empty sequence which the result should be 1
			return 1;
		int num_elements = (int) nums.size();
		int start = 0;		// "start" indicates the position of the first value we have not scanned in the sequence
		int pos = start, element = 0;
		while (start < num_elements)
		{
			pos = start;
			element = nums[pos];
			// special value indicating that the value at "pos" have been scanned
			nums[pos] = INT_MIN;
			// treat the sequence as a linked list and scan each element along the list
			while (element > 0 && element <= num_elements)
			{
				pos = element - 1;
				element = nums[pos];
				// Special value to indicate that (pos + 1 or element) has appeared in the sequence
				nums[pos] = INT_MAX;			// must not be in [1, num_elements), especially 1
			}
			while (start < num_elements && (nums[start] == INT_MAX || nums[start] == INT_MIN))		// advance to the next unscanned element
				++start;
		}
		// Linear scan the sequence to check whether the corresponding value at each position had appeared
		for (int i = 0; i != num_elements; ++i)
			if (nums[i] == INT_MIN)
				return i + 1;
		// all elements appeared, then return (num_element + 1)
		return num_elements + 1;
	}
};
