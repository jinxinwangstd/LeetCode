#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool compare(string& s1, string& s2)
{
	string str1 = s1 + s2, str2 = s2 + s1;
	return greater<string>()(str1, str2);
}

class Solution
{
public:
	string largestNumber(vector<int>& nums)
	{
		vector<string> num_strings;
		for (int num : nums)
			num_strings.push_back(to_string(num));
		sort(num_strings.begin(), num_strings.end(), compare);
		if (num_strings[0] == "0")
			return "0";
		string ret;
		for (string num : num_strings)
			ret += num;
		return ret;
	}
};
