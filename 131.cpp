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
	bool isPalindrome(const string& s, int start, int end)
	{
		int i = start, j = end - 1;
		while (i < j)
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	void partitionHelper(vector<vi>& ret, const string& s, vi& parts, int start)
	{
		if (start == s.size())
		{
			ret.push_back(parts);
			return;
		}
		for (int i = start + 1; i <= s.size(); ++i)
		{
			if (isPalindrome(s, start, i))
			{
				parts.push_back(i);
				partitionHelper(ret, s, parts, i);
				parts.pop_back();
			}
		}
		return;
	}
	vector< vector<string> > partition(string s)
	{
		vector<vi> parts_ret;
		vi parts;
		partitionHelper(parts_ret, s, parts, 0);
		vector< vector<string> > ret;
		for (int i = 0; i < parts_ret.size(); ++i)
		{
			vector<string> vs;
			int start = 0, end;
			for (int j = 0; j < parts_ret[i].size(); ++j)
			{
				end = parts_ret[i][j];
				vs.push_back(s.substr(start, end - start));
				start = end;
			}
			ret.push_back(vs);
		}
		return ret;
	}
};
