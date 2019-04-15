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
		if (!head)
			return head;
		ListNode *cur = head;
		int num = 0;
		vector<ListNode *> node_ptrs;
		while (cur)
		{
			node_ptrs.push_back(cur);
			num++;
			cur = cur->next;
		}
		if (n == num)
			return num > 1 ? node_ptrs[1] : NULL;
		int index = num - n;
		ListNode *prev = node_ptrs[index - 1], *removed = node_ptrs[index];
		prev->next = removed->next;
		return head;
	}
};
