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
	// Given a chosen set, select elements that summed up to target from the candidates set with indices in [start, candidates.size())
	// The rule that if we choose one candidate, the elements after it must be greater or equal to it helps us avoid the duplicate sets
	void backtrack(vector< vector<int> >& ret, vector<int>& candidates, vector<int>& set, int target, int start)
	{
		if (!target)			// a satisfying set
		{
			ret.push_back(set);
			return;
		}
		int i = start;
		while (i < (int) candidates.size() && candidates[i] <= target)
		{
			set.push_back(candidates[i]);		// choose a possible candidate
			backtrack(ret, candidates, set, target - candidates[i], i + 1);		// make next move where we cannot use the same element again
			set.pop_back();						// recover the set we have chosen
			while (i + 1 < (int) candidates.size() && candidates[i] == candidates[i + 1])	// advance to the last element in a same candidate sequence
				++i;
			++i;	// advance to the next different candidate
		}
		return;
	}
	vector< vector<int> > combinationSum2(vector<int>& candidates, int target)
	{
		vector< vector<int> > ret;
		vector<int> set;
		sort(candidates.begin(), candidates.end());		// sort the sequence, which is a necessary step to avoid duplicate set
		backtrack(ret, candidates, set, target, 0);		// solving the problem by selecting elements in the whole sequence
		return ret;
	}
};
