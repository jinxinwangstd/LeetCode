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
	const int num_parts = 4;
	// This function determines whether a substring of s from position start to end is a valid ip address
	bool validateIpAddresses(const string& s, int start, int len)
	{
		if (len > 1 && s[start] == '0')		// '01' or '011'
			return false;
		if (len < 3)
			return true;
		if (s[start] < '2')
			return true;
		if (s[start] == '2' && s[start + 1] < '5')
			return true;
		if (s[start] == '2' && s[start + 1] == '5' && s[start + 2] < '6')
			return true;
		return false;
	}
	// This function generates valid ip address partitions using backtracking algorithm
	// We represent an valid ip address parition by four end positions
	void generateIpAddresses(vector<vi>& ret, vi& positions, const string& s, int start)
	{
		if (positions.size() == num_parts)			// base case: we got one valid ip address
		{
			ret.push_back(positions);
			return;
		}
		if (start >= s.size())								// pruning:	no enough characters left
			return;
		int rest_num_parts = num_parts - positions.size();
		if (s.size() - start > rest_num_parts * 3)			// pruning: too many characters left
			return;
		int len;
		if (positions.size() == 3)							// arrange the last part
		{
			len = s.size() - start;
			if (len > 0 && validateIpAddresses(s, start, len))
			{
				positions.push_back(s.size());
				generateIpAddresses(ret, positions, s, s.size());				// move to the next part
				positions.pop_back();
			}
		}
		else												// arrange the first three parts
		{
			for (len = 1; len <= 3; ++len)		// try all possible length of one part
			{
				if (validateIpAddresses(s, start, len))
				{
					positions.push_back(start + len);
					generateIpAddresses(ret, positions, s, start + len);		// move to the next part
					positions.pop_back();
				}
			}
		}
		return;
	}
	vector<string> restoreIpAddresses(string s)
	{
		vector<vi> ret;
		vi positions;
		generateIpAddresses(ret, positions, s, 0);
		vector<string> addresses;
		// transforming from our representation of ip address to the actual ip address
		for (int i = 0; i != ret.size(); ++i)
		{
			addresses.push_back(s.substr(0, ret[i][0] - 0) + "." + s.substr(ret[i][0], ret[i][1] - ret[i][0]) + "." + s.substr(ret[i][1], ret[i][2] - ret[i][1]) + "." + s.substr(ret[i][2], ret[i][3] - ret[i][2]));
		}
		return addresses;
	}
};
