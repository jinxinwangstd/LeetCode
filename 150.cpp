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
	int evalRPN(vector<string>& tokens)
	{
		stack<int> s;
		for (int i = 0; i < tokens.size(); ++i)
		{
			string token = tokens[i];
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				int op2 = s.top();
				s.pop();
				int op1 = s.top();
				s.pop();
				int ret;
				if (token == "+")
					ret = op1 + op2;
				else if (token == "-")
					ret = op1 - op2;
				else if (token == "*")
					ret = op1 * op2;
				else if (token == "/")
					ret = op1 / op2;
				s.push(ret);
			}
			else
			{
				s.push(stoi(token));
			}
		}
		return s.top();
	}
};
