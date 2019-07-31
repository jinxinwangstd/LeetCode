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
	vector<int> getRow(int rowIndex)
	{
		vi ret;
		ret.push_back(1);
		if (!rowIndex)
			return ret;
		vi upper_row = getRow(rowIndex - 1);
		int size = rowIndex + 1;
		ret.resize(size);
		// generate the elements between two ending 1 at this row
		for (int i = 1; i < size - 1; i++)
			ret[i] = upper_row[i] + upper_row[i - 1];
		ret[size - 1] = 1;
		return ret;
	}
};
