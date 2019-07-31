#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class Node
{
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random)
	{
		val = _val;
		next = _next;
		random = _random;
	}
};

class Solution
{
public:
	map<Node *, Node *> record;
	Node* copyRandomList(Node* head)
	{
		record[NULL] = NULL;
		Node *cur = head, *copy_cur = NULL, *copy_head = NULL;
		while (cur)
		{
			if (!record.count(cur))
			{
				Node *copy_node = new Node(cur->val, NULL, NULL);
				if (copy_cur)
				{
					copy_cur->next = copy_node;
					copy_cur = copy_cur->next;
				}
				else
					copy_head = copy_cur = copy_node;
				record[cur] = copy_cur;
			}
			else
			{
				copy_cur->next = record[cur];
				copy_cur = copy_cur->next;
			}
			Node *copy_next = NULL, *copy_random = NULL;
			if (cur->next && !record.count(cur->next))
			{
				copy_next = new Node(cur->next->val, NULL, NULL);
				record[cur->next] = copy_next;
			}
			if (cur->random && !record.count(cur->random))
			{
				copy_random = new Node(cur->random->val, NULL, NULL);
				record[cur->random] = copy_random;
			}
			copy_cur->next = record[cur->next];
			copy_cur->random = record[cur->random];
			cur = cur->next;
		}
		return copy_head;
	}
};
