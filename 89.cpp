#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int max_size = 1000;

class Solution
{
public:
	bool find = false;
	// This function generates gray code using backtracking algorithm
	void generateGrayCode(vi& ret, int p, int n, set<int>& record, bitset<max_size>& s)
	{
		if (p == ret.size())	// base case: we got enough gray code numbers
		{
			find = true;
			return;
		}
		// try to flip each bit
		for (int i = 0; i < n; ++i)
		{
			s.flip(i);		// set the context
			int num = s.to_ulong();
			if (!record.count(num))		// flipping generates a new number
			{
				ret[p] = num;
				record.insert(num);
				generateGrayCode(ret, p + 1, n, record, s);		// move on to the next gray code number
				if (find)		// we found the gray code sequence then we don't need to try other ones
					return;
				record.erase(num);
			}
			s.flip(i);		// recover the context
		}
		return;
	}
	vector<int> grayCode(int n)
	{
		bitset<max_size> s;
		int len = 1 << n;
		vi ret(len);
		set<int> record;
		record.insert(0);
		generateGrayCode(ret, 1, n, record, s);
		return ret;
	}
};
