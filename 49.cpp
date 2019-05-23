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
	vector< vector<string> > groupAnagrams(vector<string>& strs)
	{
		map< string, vector<string> > record;
		// The anagrams would be the same after sorting, which would be key to group them
		for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); ++iter)
		{
			// get the key it corresponds to
			string sorted_str(*iter);
			sort(sorted_str.begin(), sorted_str.end());
			record[sorted_str].push_back(*iter);		// put them into the corresponding container
		}
		vector< vector<string> > ret;
		// Linear scan all containers for each anagram group
		for (map< string, vector<string> >::iterator iter = record.begin(); iter != record.end(); ++iter)
			ret.push_back(iter->second);
		return ret;
	}
};
