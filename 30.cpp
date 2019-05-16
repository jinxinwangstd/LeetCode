#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	vector<int> findSubstring(string s, vector<string>& words)
	{
		vector<int> ret;
		if (words.empty())		// corner case: empty substring
			return ret;
		unordered_map<string, int> expected;		// record the expected occurrence time for each word
		for (string word : words)
			expected[word]++;
		int num = words.size(), len = words[0].size(), n = s.size();
		// iterate through every possible substring start
		for (int i = 0; i != n - num * len + 1; ++i)
		{
			unordered_map<string, int> actual;	// record the actual occurrence time for each word
			int j = 0;
			for (j = 0; j != num; ++j)
			{
				string token = s.substr(i + j * len, len);
				// If any word does not occur in the substring or occurs more than expected, we just terminate the loop
				if (expected.find(token) != expected.end())
				{
					actual[token]++;
					if (actual[token] > expected[token])
						break;
				}
				else
					break;
			}
			// Check if we have find every word in the word list or exit the loop earlier
			if (j == num)
				ret.push_back(i);
		}
		return ret;
	}
};
