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
	vector<int> twoSum(vector<int>& numbers, int target)
	{
		unordered_map<int, vi> num_pos;
		for (int i = 0; i < numbers.size(); ++i)
		{
			num_pos[numbers[i]].push_back(i + 1);
		}
		vi ret;
		for (int i = 0; i < numbers.size(); ++i)
		{
			int num1 = numbers[i], num2 = target - num1;
			if (num1 == num2)
			{
				if (num_pos[num1].size() > 1)
				{
					ret.insert(ret.end(), num_pos[num1].begin(), num_pos[num1].end());
					return ret;
				}
			}
			else
			{
				if (num_pos.count(num2))
				{
					ret.push_back(i + 1);
					ret.push_back(num_pos[num2][0]);
					return ret;
				}
			}
		}
		return ret;
	}
};
