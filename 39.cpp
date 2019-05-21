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
		if (target == 0)					// a satisfying set
		{
			ret.push_back(set);
			return;
		}
		int i = start;
		while (i < (int) candidates.size() && candidates[i] <= target)
		{
			set.push_back(candidates[i]);	// choose that candidate
			backtrack(ret, candidates, set, target - candidates[i], i);		// next move where you can use the same element
			set.pop_back();					// recover the set to the step before we assigned that candidate
			++i;
		}
		return;
	}
	vector< vector<int> > combinationSum(vector<int>& candidates, int target)
	{
		vector< vector<int> > ret;
		vector<int> set;
		sort(candidates.begin(), candidates.end());		// sort the sequence to the ascending order, which is a necessary step to avoid duplicates
		backtrack(ret, candidates, set, target, 0);		// solve it by selecting elements in the whole candidates
		return ret;
	}
};
