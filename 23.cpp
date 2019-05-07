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
	ListNode* mergeKLists(vector<ListNode *>& lists)
	{
		int K = (int) lists.size();
		ListNode *head = NULL, *cur = NULL;		// "cur" points to the current tail of the merged list
		priority_queue< ii, vii, greater<ii> > pq;	// use heap to extract the smallest element among the front elements of K lists
		// Push the first elements of K lists into the heap
		for (int i = 0; i != K; ++i)
		{
			if (lists[i])
			{
				pq.push(make_pair(lists[i]->val, i));
				lists[i] = lists[i]->next;
			}
		}
		while (!pq.empty())
		{
			ii elem = pq.top();
			int val = elem.first, id = elem.second;	// we use "id" to record which list we extract this element from in order to bring in the next element into the heap
			pq.pop();
			if (!cur)		// the first element to be merged
			{
				head = cur = new ListNode(val);		// allocate the first node in the merged list
				if (lists[id])				// bring in the next element into the heap
				{
					pq.push(make_pair(lists[id]->val, id));
					lists[id] = lists[id]->next;
				}
				continue;
			}
			cur->next = new ListNode(val);		// allocate the next node in the merged list
			cur = cur->next;
			if (lists[id])					// bring in the next element into the heap
			{
				pq.push(make_pair(lists[id]->val, id));
				lists[id] = lists[id]->next;
			}
		}
		return head;
	}
};
