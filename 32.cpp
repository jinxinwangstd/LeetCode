#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		stack<int> st;
		// Linear scan to record the positions of all unpaired single parentheses
		for (int i = 0; i != (int) s.size(); ++i)
		{
			if (s[i] == '(')
				st.push(i);
			else if (!st.empty())
			{
				if (s[st.top()] == ')')
					st.push(i);
				else
					st.pop();
			}
			else
				st.push(i);
		}
		// the longest gap between two unpaired parentheses is the result
		int ret = 0, rear = (int) s.size(), front = 0;
		while (!st.empty())
		{
			front = st.top();
			st.pop();
			ret = max(ret, rear - front - 1);
			rear = front;
		}
		// don't forget the gap at two ends
		front = -1;
		ret = max(ret, rear - front - 1);
		return ret;
	}
};
