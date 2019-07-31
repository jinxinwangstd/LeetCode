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
	bool isPalindrome(string s)
	{
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			if (!isalnum(s[i]))
			{
				i++;
				continue;
			}
			if (!isalnum(s[j]))
			{
				j--;
				continue;
			}
			if (tolower(s[i]) != tolower(s[j]))
				return false;
			i++;
			j--;
		}
		return true;
	}
};
