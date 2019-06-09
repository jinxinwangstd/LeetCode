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
	// This function generate all valid combinations based on backtracking algorithms
	void generateCombination(vector<vi>& ret, vi& combination, int n, int pos, int start)
	{
		if (pos == (int) combination.size())		// base case: valid combination
		{
			ret.push_back(combination);
			return;
		}
		// arrange next element in the position of pos in the vector
		for (int i = start; i <= n; ++i)
		{
			combination[pos] = i;
			generateCombination(ret, combination, n, pos + 1, i + 1);
		}
		return;
	}
	// This function generate all combinations selecting k numbers from [1, n]
	vector< vector<int> > combine(int n, int k)
	{
		vector<vi> ret;
		if (n < k)
			return ret;
		vi combination(k, 0);
		generateCombination(ret, combination, n, 0, 1);
		return ret;
	}
};
