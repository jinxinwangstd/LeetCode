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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (!head)			// corner case: empty list, and we return NULL
			return head;
		ListNode *cur = head;
		int num = 0;
		vector<ListNode *> node_ptrs;
		// record the pointers to every node in the list
		while (cur)
		{
			node_ptrs.push_back(cur);
			num++;
			cur = cur->next;
		}
		// remove the first node
		if (n == num)
			return num > 1 ? node_ptrs[1] : NULL;
		// else remove other node in the list
		int index = num - n;	// find the index of the node to be removed from the start
		ListNode *prev = node_ptrs[index - 1], *removed = node_ptrs[index];
		prev->next = removed->next;		// remove it
		return head;
	}
};
