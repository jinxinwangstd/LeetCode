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
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors)
	{
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution
{
public:
	int findNode(vector<Node *>& set, Node *node)
	{
		for (int i = 0; i < set.size(); ++i)
		{
			if (set[i] == node)
				return i;
		}
		return -1;
	}
	Node* cloneGraph(Node* node)
	{
		vector<Node *> set, clone_set;
		queue<Node *> q, clone_q;
		Node *clone_start = new Node(node->val, vector<Node *>());
		q.push(node);
		set.push_back(node);
		clone_q.push(clone_start);
		clone_set.push_back(clone_start);
		while (!q.empty())
		{
			Node *v = q.front();
			q.pop();
			Node *cv = clone_q.front();
			clone_q.pop();
			for (int i = 0; i < v->neighbors.size(); ++i)
			{
				Node *n = v->neighbors[i];
				int n_pos = findNode(set, n);
				if (n_pos == -1)
				{
					Node *cn = new Node(n->val, vector<Node *>());
					q.push(n);
					set.push_back(n);
					clone_q.push(cn);
					clone_set.push_back(cn);
					cv->neighbors.push_back(cn);
				}
				else
				{
					cv->neighbors.push_back(clone_set[n_pos]);
				}
			}
		}
		return clone_start;
	}
};
