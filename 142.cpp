#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		unordered_set<ListNode *> s;
		while (head)
		{
			if (s.count(head))
				return head;
			s.insert(head);
			head = head->next;
		}
		return NULL;
	}
};
