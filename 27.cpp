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
	int removeElement(vector<int>& nums, int val)
	{
		int len = 0, cur = 0;	// len is the length of no-val list, and cur is the index of currently scanning element
		while (cur != (int) nums.size())
		{
			if (nums[cur] != val)		// if the current element is not val, copy it into the corresponding place
				nums[len++] = nums[cur];
			cur++;
		}
		return len;
	}
};
