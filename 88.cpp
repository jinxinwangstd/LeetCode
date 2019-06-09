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
	// This function merges two sorted array into one sorted array
	// The basic idea is assigning elements from the end to the start
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int i = 0, j = 0;
		while (i < m && j < n)
		{
			// assign the larger one of two arrays into the end
			if (nums1[m - 1 - i] > nums2[n - 1 - j])
			{
				nums1[m + n - 1 - i - j] = nums1[m - 1 - i];
				i++;
			}
			else
			{
				nums1[m + n - 1 - i - j] = nums2[n - 1 - j];
				j++;
			}
		}
		if (j != n)		// if the num2's elements are not all assigned, append them to the start of the num1
		{
			while (j != n)
			{
				nums1[m + n - 1 - i - j] = nums2[n - 1 - j];
				++j;
			}
		}
		return;
	}
};
