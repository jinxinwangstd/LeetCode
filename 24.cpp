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
	ListNode* swapPairs(ListNode* head)
	{
		if (!head || !head->next)		// corner case: there is only zero or one element in the list
			return head;
		ListNode *new_head = head->next, *cur = head;
		// Iterate every pair of elements in the list
		while (cur)
		{
			if (!cur->next)		// only one element in the last pair of eleements
				break;
			// swap two elements pointed by cur and cur->next
			ListNode *second = cur->next;
			cur->next = second->next;
			second->next = cur;
			// advance to the next pair of elements
			if (cur->next && cur->next->next)	// next pair has two elements
			{
				ListNode *third = cur->next;
				cur->next = cur->next->next;		// fix the link between current pair and the next pair
				cur = third;
			}
			else 								// next pair has only one element
				cur = cur->next;
		}
		return new_head;
	}
};
