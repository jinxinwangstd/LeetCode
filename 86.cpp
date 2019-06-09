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
	// This function rearranges a linked list into two parts. The first part has all elements less than x and the second part has all elements greater than or equal to x
	// The basic idea is removing all elements belonging to the second part out of the original list and put into a new list, and then linking two list together
	ListNode* partition(ListNode* head, int x)
	{
		if (!head)				// corner case: empty list
			return NULL;
		ListNode *anchor = new ListNode(0), *anchor2 = new ListNode(0);
		anchor->next = head;
		ListNode *before = anchor, *cur = before->next, *cur2 = anchor2;
		// Linear scan every node in the original list
		while (cur)
		{
			if (cur->val >= x)		// met a second part element
			{
				// put the element into the new list
				cur2->next = cur;
				cur2 = cur2->next;
				cur2->next = NULL;
				// moving the element out of the original list
				before->next = cur->next;
				cur = before->next;
			}
			else 					// met a first part element
			{
				before = cur;
				cur = before->next;
			}
		}
		if (!cur)			// corner case: the last element is removed
			cur = before;
		// Link two list together
		cur->next = anchor2->next;
		ListNode *new_head = anchor->next;
		delete(anchor);
		delete(anchor2);
		return new_head;
	}
};
