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

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		if (!head)
			return NULL;
		// calculate the length of current list
		int len = 0;
		ListNode *cur = head;
		while (cur)
		{
			len++;
			cur = cur->next;
		}
		ListNode *anchor = new ListNode(0);
		anchor->next = head;
		int root_index = len / 2;	// the index of the root node in the list
		// find the node before the root node in the linked list
		cur = anchor;
		int i = 0;
		while (i < root_index)
		{
			cur = cur->next;
			i++;
		}
		// build the root node
		TreeNode *root = new TreeNode(cur->next->val);
		ListNode *left_head = (cur == anchor ? NULL : anchor->next), *right_head = cur->next->next;
		// break the list at the position of the root node into two lists for two subtrees
		cur->next->next = NULL;
		cur->next = NULL;
		// build two subtrees
		root->left = sortedListToBST(left_head);
		root->right = sortedListToBST(right_head);
		return root;
	}
};
