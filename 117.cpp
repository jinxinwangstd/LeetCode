#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class Solution
{
public:
	Node* connect(Node* root)
	{
		Node *cur = root, *head = NULL, *tail = NULL;
		while (cur)
		{
			if (cur->left)
			{
				if (tail)
				{
					tail->next = cur->left;
					tail = tail->next;
				}
				else
					head = tail = cur->left;
			}
			if (cur->right)
			{
				if (tail)
				{
					tail->next = cur->right;
					tail = tail->next;
				}
				else
					head = tail = cur->right;
			}
			if (!(cur = cur->next))
			{
				cur = head;
				head = tail = NULL;
			}
		}
		return root;
	}
};
