#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;

vi L;	// array in which the ith element is the minimal element that can be appeared in the ith position of LIS

// Greedy + Divide&Conquer method to calculate the length of the longest increasing subsequence
int lengthOfLIS(vector<int>& nums)
{
	int size = (int) nums.size();
	for (int i = 0; i != size; ++i)
	{
		vi::iterator iter = lower_bound(L.begin(), L.end(), nums[i]);	// Find the position of the new element in the array L
		if (iter == L.end())		// greater than all elements
			L.push_back(nums[i]);
		else 						// replace one element inside the L
			*iter = nums[i];
	}
	return (int) L.size();
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	return 0;
}
