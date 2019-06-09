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
	int count;
	// This function try to generate permutations in order until it is the k-th permutation based on the backtracking algorithm
	void countPermutation(string& permutation, vi& record, int next, int k)
	{
		int n = (int) record.size();
		if (next == n)		// we have generated a valid permutation
		{
			++count;
			return;
		}
		// try all possible elements in order for the 'next' position in the permutation
		for (int i = 1; i <= n; ++i)
		{
			if (!record[i - 1])		// find one valid element
			{
				// update the context
				record[i - 1] = 1;
				permutation[next] = '0' + i;
				countPermutation(permutation, record, next + 1, k);		// move up to the next position in the permutation
				if (count == k)		// we have generated k permutation
					return;
				// recover the context
				record[i - 1] = 0;
			}
		}
		return;
	}
	string getPermutation(int n, int k)
	{
		string permutation;
		permutation.resize(n);
		vi record(n, 0);
		count = 0;
		countPermutation(permutation, record, 0, k);		// solve it
		return permutation;
	}
};
