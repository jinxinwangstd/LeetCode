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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode *curA = headA, *curB = headB;
		int lengthA = 0, lengthB = 0;
		while (curA)
		{
			lengthA++;
			curA = curA->next;
		}
		while (curB)
		{
			lengthB++;
			curB = curB->next;
		}
		curA = headA;
		curB = headB;
		int len_diff = abs(lengthA - lengthB);
		if (lengthA > lengthB)
		{
			while (len_diff)
			{
				curA = curA->next;
				len_diff--;
			}
		}
		else
		{
			while (len_diff)
			{
				curB = curB->next;
				len_diff--;
			}
		}
		while (curA && curB)
		{
			if (curA == curB)
				return curA;
			curA = curA->next;
			curB = curB->next;
		}
		return NULL;
	}
};
