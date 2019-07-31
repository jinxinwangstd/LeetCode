#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
private:
	stack<TreeNode *> s;
public:
	BSTIterator(TreeNode* root)
	{
		TreeNode *cur = root;
		while (cur)
		{
			s.push(cur);
			cur = cur->left;
		}
	}

	/** @return the next smallest number */
	int next()
	{
		TreeNode *ret = s.top();
		s.pop();
		if (ret->right)
		{
			TreeNode *cur = ret->right;
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
		}
		return ret->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return !s.empty();
	}
};
