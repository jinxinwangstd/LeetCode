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
	void traverseHelper(vi& ret, TreeNode *root)
	{
		if (root->left)
			traverseHelper(ret, root->left);
		ret.push_back(root->val);
		if (root->right)
			traverseHelper(ret, root->right);
		return;
	}
	// This function traverses one tree in order in recursive way
	vector<int> inorderTraversal(TreeNode* root)
	{
		vi ret;
		if (!root)
			return ret;
		traverseHelper(ret, root);
		return ret;
	}
};
