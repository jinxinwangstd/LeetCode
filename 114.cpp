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
	TreeNode *flattenHelper(TreeNode *root)
	{
		if (!root)
			return NULL;
		if (!root->left && !root->right)
			return root;
		TreeNode *left_end = root;
		if (root->left)
			left_end = flattenHelper(root->left);
		TreeNode *right_end = left_end;
		if (root->right)
			right_end = flattenHelper(root->right);
		left_end->right = root->right;
		if (root->left)
			root->right = root->left;
		root->left = NULL;
		return right_end;
	}
	void flatten(TreeNode* root)
	{
		flattenHelper(root);
		return;
	}
};
