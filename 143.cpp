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
	void reorderList(ListNode* head)
	{
		if (!head)
			return;
		stack<ListNode *> s;
		ListNode *reverse_head = head;
		while (reverse_head)
		{
			s.push(reverse_head);
			reverse_head = reverse_head->next;
		}
		while (true)
		{
			reverse_head = s.top();
			s.pop();
			if (reverse_head == head)
			{
				if (head->next && head->next->next)
					head->next = NULL;
				break;
			}
			// insert
			reverse_head->next = head->next == reverse_head ? NULL : head->next;
			head->next = reverse_head;
			// update head
			if (reverse_head->next)
				head = reverse_head->next;
		}
		return;
	}
};
