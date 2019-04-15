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
	vector< vector<int> > threeSum(vector<int>& nums)
	{
		vector<vi> ret;
		sort(nums.begin(), nums.end());
		for (int i = 0; i != nums.size(); ++i)
		{
			int target = -nums[i];
			int front_ptr = i + 1, rear_ptr = nums.size() - 1;
			while (front_ptr < rear_ptr)
			{
				if (nums[front_ptr] + nums[rear_ptr] < target)
					++front_ptr;
				else if (nums[front_ptr] + nums[rear_ptr] > target)
					--rear_ptr;
				else
				{
					vi triple(3, 0);
					triple[0] = nums[i];
					triple[1] = nums[front_ptr];
					triple[2] = nums[rear_ptr];
					ret.push_back(triple);

					while (front_ptr < rear_ptr && nums[front_ptr] == triple[1])
						++front_ptr;

					while (rear_ptr > front_ptr && nums[rear_ptr] == triple[2])
						--rear_ptr;
				}
			}
			while (i + 1 < nums.size() && nums[i] == nums[i + 1])
				++i;
		}
		return ret;
	}
};
