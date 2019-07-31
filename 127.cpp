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
	bool isTransformed(const string& s1, const string& s2)
	{
		int num_diff = 0;
		for (int i = 0; i < s1.size(); ++i)
		{
			num_diff += s1[i] != s2[i];
			if (num_diff > 1)
				return false;
		}
		return num_diff == 1;
	}
	int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{
		int num_word = wordList.size();
		map<string, int> lens;
		queue<string> q;
		for (int i = 0; i < num_word; ++i)
			lens[wordList[i]] = 0;
		if (!lens.count(endWord))
			return 0;
		lens[endWord] = 1;
		q.push(endWord);
		if (isTransformed(beginWord, endWord))
			return 1 + lens[endWord];
		while (!q.empty())
		{
			string word = q.front();
			q.pop();
			for (map<string, int>::iterator iter = lens.begin(); iter != lens.end(); ++iter)
			{
				if (!iter->second && isTransformed(iter->first, word))
				{
					lens[iter->first] = 1 + lens[word];
					q.push(iter->first);
					if (isTransformed(beginWord, iter->first))
						return 1 + lens[iter->first];
				}
			}
		}
		return 0;
	}
};
