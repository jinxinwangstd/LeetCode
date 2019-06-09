#include <bits/stdc++.h>

using namespace std;
using ull = int64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class Solution
{
public:
	// This function finds the minimal window string in source string that contains all characters in target string
	string minWindow(string s, string t)
	{
		string ret;
		int len_ret = INT_MAX;
		if (t.empty())				// corner case: the target string is empty then the result is also empty string
			return ret;
		// use a map to record all characters the target string contains
		map<char, int> t_map;
		for (int i = 0; i != (int) t.size(); ++i)
			++t_map[t[i]];

		int num_valid = 0;			// variable to record the number of characters that satisfying the number requirements
		map<char, int> s_map;
		int start = 0, end = 0;
		// Linear scan the source string to find all minimal window substrings
		while (end < (int) s.size())
		{
			// Find the end character of a valid substring
			while (end < (int) s.size())
			{
				char end_c = s[end];
				if (t_map.count(end_c))
				{
					++s_map[end_c];
					if (s_map[end_c] == t_map[end_c])
					{
						++num_valid;
						if (num_valid == (int) t_map.size())  	// we find it: currently s[start, end] contains all characters we need
						{
							++end;
							break;
						}
					}
				}
				++end;
			}
			// If we didn't reach the end, that indicates we find a valid end
			if (end != (int) s.size())
			{
				// Find the start character of a valid substring
				while (start < (int) s.size())
				{
					char start_c = s[start];
					if (t_map.count(start_c))
					{
						--s_map[start_c];
						// If we move over this character, the number of valid characters is not enough, then we know it is the minimal start
						if (s_map[start_c] < t_map[start_c])	// we find it: currently s[start, end] is the minimal window that contains all characters we need
						{
							int new_len = end - start;
							if (new_len < len_ret)
							{
								len_ret = new_len;
								ret = s.substr(start, new_len);
							}
							--num_valid;
							++start;
							break;
						}
					}
					++start;
				}
			}
		}
		return ret;
	}
};
