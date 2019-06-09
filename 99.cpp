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
	// This function finds the first node that is greater than the target, which is the first invalid node in the left subtree of a BST
	TreeNode *checkValidLeftSubtree(TreeNode *root, int target)
	{
		if (!root)
			return NULL;
		if (root->val >= target)
			return root;
		TreeNode *ret = checkValidLeftSubtree(root->left, target);
		if (ret)
			return ret;
		else
			ret = checkValidLeftSubtree(root->right, target);
		return ret;
	}
	// This function finds the first node that is less than the target, which is the first invalid node in the right subtree of a BST
	TreeNode *checkValidRightSubtree(TreeNode *root, int target)
	{
		if (!root)
			return NULL;
		if (root->val <= target)
			return root;
		TreeNode *ret = checkValidRightSubtree(root->left, target);
		if (ret)
			return ret;
		else
			ret = checkValidRightSubtree(root->right, target);
		return ret;
	}
	// This function recovers a BST with two elements swapped
	void recoverTree(TreeNode *root)
	{
		// base cases
		if (!root)
			return;
		if (!root->left && !root->right)
			return;
		/* There are only three cases of swapping two elements in a BST:
		 * 1. Swap an element in the left subtree with the root element
		 * 2. Swap an element in the right subtree with the root element
		 * 3. Swap an element in the left subtree with one element in the right subtree
		 */
		TreeNode *left_ret = checkValidLeftSubtree(root->left, root->val);
		TreeNode *right_ret = checkValidRightSubtree(root->right, root->val);
		// Repeated fix invalid elements with current root
		while (left_ret || right_ret)
		{
			if (left_ret && right_ret)							// case 3
				swap(left_ret->val, right_ret->val);
			else if (left_ret && root->val < left_ret->val)		// case 1
				swap(left_ret->val, root->val);
			else if (right_ret && root->val > right_ret->val)	// case 2
				swap(right_ret->val, root->val);
			// Recheck the BST
			left_ret = checkValidLeftSubtree(root->left, root->val);
			right_ret = checkValidRightSubtree(root->right, root->val);
		}
		// With the current root the tree is valid, then we fix the two subtrees
		recoverTree(root->left);
		recoverTree(root->right);
		return;
	}
};
