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
	int lengthOfLongestSubstringTwoDistinct(string s)
	{
		map<char, int> record;
		int ret = 0, num = s.size();
		int start = 0, end = 0;
		while (end < num)
		{
			char c = s[end];
			if (record.count(c))
			{
				record[c] = end;
			}
			else
			{
				if (record.size() < 2)
				{
					record[c] = end;
				}
				else
				{
					ret = max(ret, end - start);
					char removed;
					int new_start = INT_MAX;
					for (map<char, int>::iterator iter = record.begin(); iter != record.end(); ++iter)
					{
						if (iter->second < new_start)
						{
							new_start = iter->second;
							removed = iter->first;
						}
					}
					start = new_start + 1;
					record.erase(removed);
					record[c] = end;
				}
			}
			end++;
		}
		ret = max(ret, end - start);
		return ret;
	}
};
