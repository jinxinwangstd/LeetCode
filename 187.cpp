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
	vector<string> findRepeatedDnaSequences(string s)
	{
		unordered_map<string, int> record;
		for (int i = 0; i <= (int)s.size() - 10; ++i)
			record[s.substr(i, 10)]++;
		vector<string> ret;
		for (unordered_map<string, int>::iterator iter = record.begin(); iter != record.end(); ++iter)
			if (iter->second > 1)
				ret.push_back(iter->first);
		return ret;
	}
};
