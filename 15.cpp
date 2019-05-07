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
		sort(nums.begin(), nums.end());			// sort the array so we can avoid triple duplicates with some techniques
		for (int i = 0; i != nums.size(); ++i)	// enumerate the first number in a three sum
		{
			int target = -nums[i];
			int front_ptr = i + 1, rear_ptr = nums.size() - 1;	// the second number starts from right behind the first number; and the third number starts from the end
			while (front_ptr < rear_ptr)	// there are valid combination of the second and the third number, which is third number >= second number
			{
				if (nums[front_ptr] + nums[rear_ptr] < target)			// increase the second number
					++front_ptr;
				else if (nums[front_ptr] + nums[rear_ptr] > target)		// decrease the third number
					--rear_ptr;
				else									// valid triple
				{
					vi triple(3, 0);
					triple[0] = nums[i];
					triple[1] = nums[front_ptr];
					triple[2] = nums[rear_ptr];
					ret.push_back(triple);

					while (front_ptr < rear_ptr && nums[front_ptr] == triple[1])	// update the pointer of the second element pointing to the next different second number
						++front_ptr;

					while (rear_ptr > front_ptr && nums[rear_ptr] == triple[2])		// update the pointer of the third element pointing to the next different third number
						--rear_ptr;
				}
			}
			while (i + 1 < nums.size() && nums[i] == nums[i + 1])	// if there are consecutive same numbers, update the pointer of the first element pointing to the last one
				++i;
		}
		return ret;
	}
};
