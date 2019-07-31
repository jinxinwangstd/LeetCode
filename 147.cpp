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
	ListNode* insertionSortList(ListNode* head)
	{
		ListNode *anchor = new ListNode(-1);
		while (head)
		{
			ListNode *node = head;
			head = head->next;
			ListNode *insert_pos = anchor;
			while (insert_pos->next && insert_pos->next->val < node->val)
				insert_pos = insert_pos->next;
			// insert
			node->next = insert_pos->next;
			insert_pos->next = node;
		}
		return anchor->next;
	}
};
