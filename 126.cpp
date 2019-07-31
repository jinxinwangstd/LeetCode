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
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
	{
		unordered_set wordSet(wordList.begin(), wordList.end());
		vector< vector<string> > ans;
		queue< vector<string> > paths;
		paths.push({beginWord});
		int level = 1;
		int minLevel = INT_MAX;

		unordered_set<string> visited;

		while (!paths.empty())
		{
			vector<string> path = paths.front();
			paths.pop();
			if (path.size() > level)
			{
				for (string w : visited) wordSet.erase(w);
				visited.clear();
				if (path.size() > minLevel)
					break;
				else
					level = path.size();
			}
			string last = path.back();
			for (int i = 0; i < last.size(); ++i)
			{
				string news = last;
				for (char c = 'a'; c <= 'z'; ++c)
				{
					news[i] = c;
					if (wordSet.find(news) != wordSet.end())
					{
						vector<string> newpath = path;
						newpath.push_back(news);
						visited.insert(news);
						if (news == endWord)
						{
							minLevel = level;
							ans.push_back(newpath);
						}
						else
							paths.push(newpath);
					}
				}
			}
		}
		return ans;
	}
};
