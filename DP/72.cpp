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
	// The state is represented by the two starting positions of two substrings to transform or compare
	int minDistanceHelper(vector<vi>& memo, string& word1, int p1, string& word2, int p2)
	{
		if (memo[p1][p2] != -1)		// we have visited this state
			return memo[p1][p2];
		// base cases
		if (p1 == word1.size() && p2 == word2.size())
			return memo[p1][p2] = 0;
		else if (p1 == word1.size())
			return memo[p1][p2] = word2.size() - p2;
		else if (p2 == word2.size())
			return memo[p1][p2] = word1.size() - p1;
		// Use recursive relation to calculate this state
		int ret = INT_MAX;
		ret = min(ret, 1 + minDistanceHelper(memo, word1, p1 + 1, word2, p2));	// delete
		ret = min(ret, 1 + minDistanceHelper(memo, word1, p1, word2, p2 + 1));	// insert
		if (word1[p1] == word2[p2])
			ret = min(ret, minDistanceHelper(memo, word1, p1 + 1, word2, p2 + 1));		// no operation because it is the same at this position
		else
			ret = min(ret, 1 + minDistanceHelper(memo, word1, p1 + 1, word2, p2 + 1));	// replace
		return memo[p1][p2] = ret;
	}
	// This function calculates the minimum number of operations to transform word1 into word2 based on the dynamic programming algorithms
	int minDistance(string word1, string word2)
	{
		int len1 = (int) word1.size(), len2 = (int) word2.size();
		vi row(len2 + 1, -1);
		vector<vi> memo(len1 + 1, row);
		int ret = minDistanceHelper(memo, word1, 0, word2, 0);
		return ret;
	}
};
