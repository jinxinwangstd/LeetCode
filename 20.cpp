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
		// Use stack to pair couple of valid parentheses
		stack<char> remains;
		for (int i = 0; i != (int) s.size(); ++i)
		{
			if (remains.empty())		// no remain parentheses
				remains.push(s[i]);
			else if (s[i] == '(' || s[i] == '{' || s[i] == '[')		// next parentheses is left parentheses so we cannot pair it with the last one
				remains.push(s[i]);
			else						// next parentheses is right parentheses
			{
				char last = remains.top();
				// only valid pair can be removed
				if ((s[i] == ')' && last == '(') ||
				        (s[i] == '}' && last == '{') ||
				        (s[i] == ']' && last == '['))
					remains.pop();
				else
					remains.push(s[i]);
			}
		}
		// Empty means all pairs are valid so they are all removed
		return remains.empty();
	}
};
