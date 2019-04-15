#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> remains;
		for (int i = 0; i != (int) s.size(); ++i)
		{
			if (remains.empty())
				remains.push(s[i]);
			else if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				remains.push(s[i]);
			else
			{
				char last = remains.top();
				if ((s[i] == ')' && last == '(') ||
				        (s[i] == '}' && last == '{') ||
				        (s[i] == ']' && last == '['))
					remains.pop();
				else
					remains.push(s[i]);
			}
		}
		return remains.empty();
	}
};
