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
	// This function removed the duplicates and make all elements appeared only once
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (!head || !head->next)
			return head;
		// we use two pointers to track the current element and the one after the current element which may be duplicates
		ListNode *cur = head, *after = cur->next;
		while (cur)
		{
			while (after)
			{
				// remove all duplicates with leaving only the first one
				if (after->val == cur->val)
				{
					cur->next = after->next;
					after = cur->next;
				}
				else
					break;
			}
			// move on to the next one
			cur = after;
			after = cur ? cur->next : nullptr;
		}
		return head;
	}
};
