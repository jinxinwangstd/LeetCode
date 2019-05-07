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
		if (!l1 || !l2)			// corner case: at least one list is empty, then we return another list head
			return l1 ? l1 : l2;
		ListNode *head = NULL, *cur1 = l1, *cur2 = l2;	// cur1 and cur2 are the pointers to the next node to be added to the merged list, and the smaller one of them is current tail node
		head = cur1->val < cur2->val ? cur1 : cur2;
		bool tail_on_l1 = (head == cur1);				// the last added node is the tail of the merged list, so tail_on_l1 indicate whether the last node is in l1 when the two current nodes have equal values
		while (cur1 != NULL && cur2 != NULL)
		{
			if (cur1->val < cur2->val)		// cur1's value comes before cur2's value, which means that the cur1 is the current tail node
			{
				ListNode *cur_tail = cur1;
				cur1 = cur1->next;
				// determine the next tail node
				cur_tail->next = cur_tail->next ? (cur_tail->next->val < cur2->val ? cur_tail->next : cur2) : cur2;
				tail_on_l1 = false;		// when cur_tail->next->value == cur2->value, the next tail node is in l2
			}
			else if (cur1->val > cur2->val)		// cur2's value comes before cur1's value, which means that the cur2 is the current tail node
			{
				ListNode *cur_tail = cur2;
				cur2 = cur2->next;
				// determine the next tail node
				cur_tail->next = cur_tail->next ? (cur_tail->next->val < cur1->val ? cur_tail->next : cur1) : cur1;
				tail_on_l1 = true;		// when cur_tail->next->value == cur2->value, the next tail node is in l1
			}
			else								// cur1 andh cur2's values are equal
			{
				// In this case, we need to link current tail to the other equal node
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
				tail_on_l1 = !tail_on_l1;	// the next tail node is in the other list
			}
		}
		return head;
	}
};
