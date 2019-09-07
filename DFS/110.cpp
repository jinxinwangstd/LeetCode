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
	// This function calculates the height of the current binary tree with 'root' node with the up level node has a height of 'height'
	int calculateTreeHeight(TreeNode *root, int height)
	{
		if (!root)
			return height;
		int ret = height + 1, left_height = 0, right_height = 0;
		if (root->left)
			left_height = calculateTreeHeight(root->left, ret);
		if (root->right)
			right_height = calculateTreeHeight(root->right, ret);
		return max(ret, max(left_height, right_height));
	}
	// This function determines whether a binary tree is height balanced
	bool isBalanced(TreeNode* root)
	{
		if (!root)				// base case
			return true;
		// for a height-balanced tree, its two subtrees must be height-balanced
		if (!isBalanced(root->left) || !isBalanced(root->right))
			return false;
		// determine whether the two subtrees' heights are balanced
		int left_height = calculateTreeHeight(root->left, 0);
		int right_height = calculateTreeHeight(root->right, 0);
		return abs(left_height - right_height) <= 1;
	}
};
