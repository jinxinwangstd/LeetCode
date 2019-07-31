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
	// This function determines whether two trees are the same
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		if (!p && !q)
			return true;
		if (p && !q)
			return false;
		if (!p && q)
			return false;
		if (p->val != q->val)
			return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
	// This function generates a symmetric tree according to the given tree
	TreeNode *generateSymmetricTree(TreeNode *root)
	{
		if (!root)
			return root;
		TreeNode *new_root = new TreeNode(root->val);
		TreeNode *new_left = generateSymmetricTree(root->right);	// generate the symmetric one of its right subtree as the new left subtree
		TreeNode *new_right = generateSymmetricTree(root->left);	// generate the symmetric one of its left subtree as the new right subtree
		new_root->left = new_left;
		new_root->right = new_right;
		return new_root;
	}
	// This function determines whether a tree is symmetric
	// The basic idea is to generate its symmetric tree and check whether they are the same
	bool isSymmetric(TreeNode* root)
	{
		TreeNode *symmetric = generateSymmetricTree(root);
		return isSameTree(root, symmetric);
	}
};
