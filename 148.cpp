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
	// Split a list with length n from the head and return the head of the second part
	ListNode *split(ListNode *head, int n)
	{
		for (int i = 1; head && i < n; ++i)
			head = head->next;
		if (!head)
			return NULL;
		ListNode *second = head->next;
		head->next = NULL;
		return second;
	}
	// merge list l1 and list l2 and append them to the list head
	ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head)
	{
		ListNode *cur = head;
		while (l1 && l2)
		{
			if (l1->val > l2->val)
			{
				cur->next = l2;
				l2 = l2->next;
				cur = cur->next;
			}
			else
			{
				cur->next = l1;
				l1 = l1->next;
				cur = cur->next;
			}
		}
		cur->next = l1 ? l1 : l2;
		while (cur->next)
			cur = cur->next;
		return cur;
	}
	//
	ListNode* sortList(ListNode* head)
	{
		if (!head || !head->next)
			return head;
		int length = 0;
		ListNode *cur = head;
		while (cur)
		{
			length++;
			cur = cur->next;
		}
		ListNode *anchor = new ListNode(0);
		anchor->next = head;
		ListNode *left = NULL, *right = NULL, *tail = NULL;
		for (int step = 1; step < length; step <<= 1)
		{
			cur = anchor->next;
			tail = anchor;
			while (cur)
			{
				left = cur;
				right = split(left, step);
				cur = split(right, step);
				tail = merge(left, right, tail);
			}
		}
		return anchor->next;
	}
};
