#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

// Every new min element has a record of the former min element (the min element under this new element), like a linked list
class MinStack
{
public:
	typedef pair<int, int> ii;
	MinStack() : min(INT_MAX)
	{}

	void push(int x)
	{
		if (x > min)
			s.push(make_pair(x, 0));
		else
		{
			s.push(make_pair(x, min));
			min = x;
		}
	}

	void pop()
	{
		ii x = s.top();
		if (x.first == min)
			min = x.second;
		s.pop();
	}

	int top()
	{
		return s.top().first;
	}

	int getMin()
	{
		return min;
	}

private:
	stack<ii> s;
	int min;
};

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	MinStack minStack = new MinStack();
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	minStack.getMin();
	minStack.pop();
	minStack.top();
	minStack.getMin();
}
