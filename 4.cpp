#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int size1 = (int) nums1.size(), size2 = (int) nums2.size();
		// calculate the two median number positions
		int med_pos1, med_pos2;
		if ((size1 + size2) % 2)
			med_pos1 = med_pos2 = (size1 + size2 - 1) / 2;
		else
		{
			med_pos1 = (size1 + size2) / 2 - 1;
			med_pos2 = (size1 + size2) / 2;
		}
		int med1, med2, i1 = 0, i2 = 0;
		bool find_med1 = false, find_med2 = false;
		// Linear scan two list to find the two median number by maintaining two pointers pointing to elements in two list
		while (!find_med1 || !find_med2)
		{
			// the minimum one of elements pointed is the (i1 + i2)th element in the combined list
			if (i1 + i2 == med_pos1)	// it is the first median number
			{
				if (i1 == size1)
					med1 = nums2[i2];
				else if (i2 == size2)
					med1 = nums1[i1];
				else
					med1 = min(nums1[i1], nums2[i2]);
				find_med1 = true;
			}
			if (i1 + i2 == med_pos2)	// it is the second median number
			{
				if (i1 == size1)
					med2 = nums2[i2];
				else if (i2 == size2)
					med2 = nums1[i1];
				else
					med2 = min(nums1[i1], nums2[i2]);
				find_med2 = true;
			}
			// advance to the next element of the combined list by increasing the pointer pointing to the minimum one
			if (i1 == size1)
				++i2;
			else if (i2 == size2)
				++i1;
			else
				nums1[i1] < nums2[i2] ? ++i1 : ++i2;
		}
		return (med1 + med2) / (double) 2;
	}
};
