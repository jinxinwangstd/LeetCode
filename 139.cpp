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
	vi memo;
	bool matchWord(const string& s, int start, unordered_set<string>& wordDict)
	{
		if (start == s.size())
			return true;
		if (memo[start] != -1)
			return (bool) memo[start];
		int rest_len = s.size() - start;
		for (int len = rest_len; len > 0; --len)
		{
			if (wordDict.count(s.substr(start, len)) && matchWord(s, start + len, wordDict))
				return memo[start] = true;
		}
		return memo[start] = false;
	}
	bool wordBreak(string s, vector<string>& wordDict)
	{
		unordered_set<string> wordSet;
		for (vector<string>::iterator iter = wordDict.begin(); iter != wordDict.end(); ++iter)
			wordSet.insert(*iter);
		memo.assign(s.size(), -1);
		return matchWord(s, 0, wordSet);
	}
};
