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
	void reverseWords(vector<char>& s)
	{
		// get all word lengths in reverse order
		vi lengths;
		int length = 0;
		for (int i = s.size() - 1; i >= 0; --i)
		{
			if (s[i] == ' ')
			{
				lengths.push_back(length);
				length = 0;
			}
			else
				length++;
		}
		lengths.push_back(length);
		// reverse all characters
		for (int i = 0; i < (s.size() + 1) / 2; ++i)
			swap(s[i], s[s.size() - 1 - i]);
		// reverse each word's characters
		for (vi::iterator iter = lengths.begin(); iter != lengths.end(); ++iter)
		{
			int start = accumulate(lengths.begin(), iter, 0) + (iter - lengths.begin());
			for (int i = 0; i < (*iter + 1) / 2; ++i)
				swap(s[start + i], s[start + *iter - 1 - i]);
		}
		return;
	}
};
