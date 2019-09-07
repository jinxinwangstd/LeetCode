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
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
	{
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution
{
public:
	Node* connect(Node* root)
	{
		if (!root)
			return NULL;
		if (!root->left && !root->right)
			return root;
		connect(root->left);
		connect(root->right);
		Node *left_cur = root->left;
		Node *right_cur = root->right;
		while (left_cur && right_cur)
		{
			left_cur->next = right_cur;
			left_cur = left_cur->right;
			right_cur = right_cur->left;
		}
		return root;
	}
};
