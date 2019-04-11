#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	int n, m, freq = 0;
	bool first = true;
	vector<int> ret;
	// In order traversal
	void traverse(TreeNode *u)
	{
		if (u->left)
			traverse(u->left);
		if (first)
		{
			n = u->val;
			m = 1;
			first = false;
		}
		else
		{
			if (u->val == n)
				++m;
			else
			{
				if (m > freq)
				{
					ret.clear();
					ret.push_back(n);
					freq = m;
				}
				else if (m == freq)
					ret.push_back(n);
				n = u->val;
				m = 1;
			}
		}
		if (u->right)
			traverse(u->right);
	}
	vector<int> findMode(TreeNode *root)
	{
		if (!root)
			return ret;
		traverse(root);
		if (m > freq)
		{
			ret.clear();
			ret.push_back(n);
		}
		else if (m == freq)
			ret.push_back(n);
		return ret;
	}
};
