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
	bool isValidBST(TreeNode *root)
	{
		if (!root)							// base case: empty tree
			return true;
		if (!isValidBST(root->left))		// validate the left subtree
			return false;
		if (!isValidBST(root->right))		// validate the right subtree
			return false;
		// find the maximum one in the left subtree
		TreeNode *left_root = root->left, *right_root = root->right;
		while (left_root && left_root->right)
			left_root = left_root->right;
		// check the quantity relationship between the left subtree with the root
		if (left_root && left_root->val >= root->val)
			return false;
		// find the minimum one in the right subtree
		while (right_root && right_root->left)
			right_root = right_root->left;
		// check the quantity relationship between the right subtree with the root
		if (right_root && right_root->val <= root->val)
			return false;
		return true;
	}
};
