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
	// This function calculate the largest sum of a subarray of the given array
	// The main idea is to separate the array into many segments, and the sum of each segment is <= 0 except the last one
	// we just calculate the largest subarray in each segment
	int maxSubArray(vector<int>& nums)
	{
		if (nums.empty())		// corner case: the array is empty then we just return 0
			return 0;
		int start = 0, sum = 0, max_sum = INT_MIN, n = (int) nums.size();
		while (start < n)
		{
			// calculate the sum of current segment
			sum += nums[start];
			if (sum > max_sum)
				max_sum = sum;
			// if the sum of current segment is <= 0, then we can start a new segment
			// the next segment don't need to include the previous segment because it would not contribute to its sum
			// any subarray of the previous segment to its right bound is <= 0
			if (sum <= 0)
				sum = 0;
			++start;
		}
		return max_sum;
	}
};
