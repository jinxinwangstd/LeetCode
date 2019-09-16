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
	unordered_map< string, vector<string> > memo;
	vector<string> concatenate(vector<string> prev, string word)
	{
		for (int i = 0; i < prev.size(); ++i)
			prev[i] += " " + word;
		return prev;
	}
	vector<string> wordBreak(string s, unordered_set<string>& wordDict)
	{
		if (memo.count(s))
			return memo[s];
		vector<string> ret;
		if (wordDict.count(s))
			ret.push_back(s);
		for (int i = 1; i < s.size(); ++i)
		{
			string word = s.substr(i);
			if (wordDict.count(word))
			{
				string res = s.substr(0, i);
				vector<string> combined = concatenate(wordBreak(res, wordDict), word);
				ret.insert(ret.end(), combined.begin(), combined.end());
			}
		}
		return memo[s] = ret;
	}
	vector<string> wordBreak(string s, vector<string>& wordDict)
	{
		unordered_set<string> wordSet;
		for (vector<string>::iterator iter = wordDict.begin(); iter != wordDict.end(); ++iter)
			wordSet.insert(*iter);
		return wordBreak(s, wordSet);
	}
};
