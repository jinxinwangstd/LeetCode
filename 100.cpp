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
}

class Solution
{
public:
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		if (!p && !q)
			return true;
		if (!p && q || p && !q)
			return false;
		if (p->val != q->val)		// compare root value
			return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);		// compare left subtrees and right subtrees
	}
};
