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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (!l1 || !l2)
			return l1 ? l1 : l2;
		ListNode *head = NULL, *cur1 = l1, *cur2 = l2;
		head = cur1->val < cur2->val ? cur1 : cur2;
		bool tail_on_l1 = head == cur1;
		while (cur1 != NULL && cur2 != NULL)
		{
			if (cur1->val < cur2->val)
			{
				ListNode *first = cur1;
				cur1 = cur1->next;
				if (!first->next)
					first->next = cur2;
				else
					first->next = first->next->val < cur2->val ? first->next : cur2;
				tail_on_l1 = false;
			}
			else if (cur1->val > cur2->val)
			{
				ListNode *first = cur2;
				cur2 = cur2->next;
				first->next = first->next ? (first->next->val < cur1->val ? first->next : cur1) : cur1;
				tail_on_l1 = true;
			}
			else
			{
				if (tail_on_l1)
				{
					ListNode *next = cur1->next;
					cur1->next = cur2;
					cur1 = next;
				}
				else
				{
					ListNode *next = cur2->next;
					cur2->next = cur1;
					cur2 = next;
				}
				tail_on_l1 = !tail_on_l1;
			}
		}
		return head;
	}
};
