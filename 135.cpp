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
	int candy(vector<int>& ratings)
	{
		int num = ratings.size(), counter = ratings.size();
		vi candies(num, 0);
		while (counter)
		{
			for (int i = 0; i < num; ++i)
			{
				if (candies[i])
					continue;
				bool left_higher = i - 1 >= 0 && ratings[i] > ratings[i - 1];
				bool right_higher = i + 1 < num && ratings[i] > ratings[i + 1];
				if (!left_higher && !right_higher)
				{
					candies[i] = 1;
					counter--;
					continue;
				}
				if (left_higher && !candies[i - 1] || right_higher && !candies[i + 1])
					continue;
				if (left_higher)
					candies[i] = max(candies[i], candies[i - 1] + 1);
				if (right_higher)
					candies[i] = max(candies[i], candies[i + 1] + 1);
				counter--;
			}
			for (int i = num - 1; i >= 0; --i)
			{
				if (candies[i])
					continue;
				bool left_higher = i - 1 >= 0 && ratings[i] > ratings[i - 1];
				bool right_higher = i + 1 < num && ratings[i] > ratings[i + 1];
				if (!left_higher && !right_higher)
				{
					candies[i] = 1;
					counter--;
					continue;
				}
				if (left_higher && !candies[i - 1] || right_higher && !candies[i + 1])
					continue;
				if (left_higher)
					candies[i] = max(candies[i], candies[i - 1] + 1);
				if (right_higher)
					candies[i] = max(candies[i], candies[i + 1] + 1);
				counter--;
			}
		}
		return accumulate(candies.begin(), candies.end(), 0);
	}
};
