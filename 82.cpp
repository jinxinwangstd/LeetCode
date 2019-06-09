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
	// This function deletes all duplicates numbers in an array
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (!head || !head->next)		// corner case: array with zero or one element
			return head;
		// use anchor element to handle some cases such as deleting the first element
		ListNode *anchor = new ListNode(0);
		anchor->next = head;
		// we use three pointers to track the current element, the one before the current element and the one after the current element which may be duplicates
		ListNode *before = anchor, *cur = head, *after = head->next;
		bool dup_flag = false;		// flag to indicate whether the current element has duplicates
		while (cur)
		{
			while (after)
			{
				// remove all duplicates with leaving the first one
				if (after->val == cur->val)
				{
					dup_flag = true;
					cur->next = after->next;
					after = cur->next;
				}
				else
					break;
			}
			// now cur->next is null or a different node
			if (dup_flag)		// remove current element if it had duplicates and not move on to the next one
			{
				before->next = cur->next;
				cur = before->next;
				after = cur ? cur->next : nullptr;
			}
			else				// move to the next element
			{
				before = cur;
				cur = cur->next;
				after = cur ? cur->next : nullptr;
			}
			dup_flag = false;
		}
		head = anchor->next;
		delete(anchor);
		return head;
	}
};
