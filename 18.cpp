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
	vector< vector<int> > fourSum(vector<int>& nums, int target)
	{
		vector<vi> ret;
		int num = (int) nums.size();
		sort(nums.begin(), nums.end());
		// Enumerate the first and second elements in a four sum
		for (int i = 0; i != num; ++i)
		{
			for (int j = i + 1; j != num; ++j)
			{
				int front_ptr = j + 1;
				int rear_ptr = num - 1;
				int rest = target - nums[i] - nums[j];
				// Find the valid combination of the third and fourth elements
				while (front_ptr < rear_ptr)
				{
					if (nums[front_ptr] + nums[rear_ptr] < rest)		// increase the third element
						++front_ptr;
					else if (nums[front_ptr] + nums[rear_ptr] > rest)	// decrease the fourth element
						--rear_ptr;
					else												// valid four sum
					{
						vi quadruplet(4, 0);
						quadruplet[0] = nums[i];
						quadruplet[1] = nums[j];
						quadruplet[2] = nums[front_ptr];
						quadruplet[3] = nums[rear_ptr];
						ret.push_back(quadruplet);

						while (front_ptr <= rear_ptr && nums[front_ptr] == quadruplet[2])	// update the pointer of the third element to the next different value
							++front_ptr;

						while (rear_ptr >= front_ptr && nums[rear_ptr] == quadruplet[3])	// update the pointer of the fourth element to the next different value
							--rear_ptr;
					}
				}
				while (j + 1 < num && nums[j + 1] == nums[j])	// update the pointer of the second element to the last same value
					++j;
			}
			while (i + 1 < num && nums[i + 1] == nums[i])	// update the pointer of the first element to the last same value
				++i;
		}
		return ret;
	}
};
