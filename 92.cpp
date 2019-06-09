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
	// This function reverses a linked list from position m to n in one pass
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		ListNode *anchor = new ListNode(0);
		anchor->next = head;
		int cur_i = 0;
		ListNode *cur = anchor;
		// find the node at position m-1
		while (cur_i + 1 < m)
		{
			cur = cur->next;
			cur_i++;
		}
		ListNode *before = cur, *reverse_end = cur->next, *reverse_head = new ListNode(0);
		// move and reverse nodes from position m to n to a new list
		while (cur_i + 1 <= n)
		{
			ListNode *remove = before->next;
			// remove it from the original list
			before->next = before->next->next;
			// insert into the beginning of the new list
			remove->next = reverse_head->next;
			reverse_head->next = remove;
			// move to the next element
			cur_i++;
		}
		// insert back into the original list
		reverse_end->next = before->next;
		before->next = reverse_head->next;
		ListNode *new_head = anchor->next;
		delete(anchor);
		delete(reverse_head);
		return new_head;
	}
};
