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
	vector< vector<int> > generate(int numRows)
	{
		vector<vi> ret;
		if (!numRows)
			return ret;
		vi cur;
		int i = 0;
		cur.push_back(1);
		ret.push_back(cur);
		i++;
		if (numRows == i)
			return ret;
		cur.push_back(1);
		ret.push_back(cur);
		i++;
		if (numRows == i)
			return ret;
		while (i != numRows)
		{
			vi next;
			next.push_back(1);
			for (int i = 1; i < cur.size(); ++i)
				next.push_back(cur[i - 1] + cur[i]);
			next.push_back(1);
			ret.push_back(next);
			cur = next;
			i++;
		}
		return ret;
	}
};
