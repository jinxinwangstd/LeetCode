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
	// This function rotates a linked list k position to its right
	ListNode* rotateRight(ListNode* head, int k)
	{
		// count the length of the list
		int len = 0;
		ListNode *cur = head;
		while (cur)
		{
			++len;
			cur = cur->next;
		}
		if (!len)			// corner case: the list is empty
			return head;
		// calculate the minimum offset we need to rotate to the right
		int offset = k % len;
		if (!offset)		// corner case: the list need not to be rotated
			return head;
		int remain = len - offset;
		// find the new head and set the new end to the NULL
		int i = 1;
		cur = head;
		while (i != remain)
		{
			cur = cur->next;
			i++;
		}
		ListNode *new_head = cur->next;
		cur->next = NULL;
		// find the original end and link it with the original start
		cur = new_head;
		while (cur->next)
			cur = cur->next;
		cur->next = head;
		// return the new head
		return new_head;
	}
};
