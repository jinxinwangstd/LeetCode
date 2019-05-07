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
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.empty())		// corner case: the number list is empty
			return 0;
		int len = 1, cur = 1;	// len is the length of non-repeated list, and cur is the index of current scanning element
		// Linear scanning the list and we ensure that the first len elements are non-repeated
		while (cur != (int) nums.size())
		{
			if (nums[cur] != nums[len - 1])		// if it is not repeated to its former element, copy it into the corresponding place
				nums[len++] = nums[cur];
			++cur;
		}
		return len;
	}
};
