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
	// This function reverse a group of elements from "start" to "end" (inclusive)
	void reverseHelper(ListNode *before, ListNode *start, ListNode *end)
	{
		ListNode *after = end->next, *cur = start, *next = cur->next, *last = after;
		// Starting from the front, break the link to next and reverse them one by one
		while (cur != after)
		{
			cur->next = last;
			last = cur;
			cur = next;
			if (cur)	// advance to the next element in the group
				next = cur->next;
		}
		before->next = end;		// fix the link between the element before this group and the new head of this group
		return;
	}
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		ListNode *new_head = new ListNode(0);	// we need a anchor
		new_head->next = head;
		ListNode *before = new_head, *start = head, *end = NULL;
		while (true)
		{
			int num = 0;
			ListNode *cur = start;
			// count k elements starting from cur
			while (cur)
			{
				num++;
				if (num == k)
				{
					end = cur;
					break;
				}
				cur = cur->next;
			}
			if (num == k)		// there are k elements in next group
			{
				reverseHelper(before, start, end);
				before = start;
				start = before->next;
			}
			else 				// no enough k elements in a group, then we stop reversing
				break;
		}
		ListNode *anchor = new_head;
		new_head = new_head->next;
		delete anchor;			// clean up
		return new_head;
	}
};
