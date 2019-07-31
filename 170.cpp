#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class TwoSum
{
private:
	unordered_map<int, int> nums;
	unordered_set<int> sums;
public:
	/** Initialize your data structure here. */
	TwoSum()
	{
		;
	}

	/** Add the number to an internal data structure.. */
	void add(int number)
	{
		nums[number]++;
	}

	/** Find if there exists any pair of numbers which sum is equal to the value. */
	bool find(int value)
	{
		if (sums.count(value))
			return true;
		for (unordered_map<int, int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
		{
			int num1 = iter->first, num2 = value - num1;
			if (num1 == num2)
			{
				if (nums[num1] > 1)
				{
					sums.insert(value);
					return true;
				}
			}
			else
			{
				if (nums.count(num2))
				{
					sums.insert(value);
					return true;
				}
			}
		}
		return false;
	}
};
