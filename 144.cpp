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

class Solution
{
public:
	void preorder(TreeNode *root, vi& ret)
	{
		if (!root)
			return;
		ret.push_back(root->val);
		preorder(root->left, ret);
		preorder(root->right, ret);
		return;
	}
	vector<int> preorderTraversal(TreeNode* root)
	{
		vi ret;
		preorder(root, ret);
		return ret;
	}
};
