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
	int longestConsecutive(vector<int>& nums)
	{
		unordered_map<int, int> m;
		int ret = 0;
		for (int num : nums)
		{
			if (m[num])
				continue;
			int len = m[num - 1] + m[num + 1] + 1;
			m[num] = m[num + m[num + 1]] = m[num - m[num - 1]] = len;
			ret = max(ret, len);
		}
		return ret;
	}
};
