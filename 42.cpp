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
	int trap(vector<int>& height)
	{
		int left = 0, right = 0;
		bool up = false, down = false;
		int length = (int) height.size();
		while (right < length)
		{
			while (!down && right + 1 < length && height[right + 1] > height[left])
			{
				++right;
				++left;
			}
			if (right + 1 == length)
				break;
			++right;
			down = true;
			while (!up && right + 1 < length && height[right + 1] < height[right])
				++right;
		}
	};
