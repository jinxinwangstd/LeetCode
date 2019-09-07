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
	TreeNode *buildTreeHelper(vi& inorder, int in_start, int in_end, vi& postorder, int post_start, int post_end)
	{
		// base case: the tree contains no value so that it would be an empty tree
		if (in_start == in_end)
			return NULL;
		// recursively build the binary tree
		// find the root node
		int root_value = postorder[post_end - 1];
		TreeNode *root = new TreeNode(root_value);
		// find the value range of the left subtree
		int left_in_start = in_start, left_post_start = post_start, left_len = 0;
		while (left_len < (in_end - in_start) && inorder[left_in_start + left_len] != root_value)
			left_len++;
		// find the value range of the right subtree
		int right_in_start = in_start + left_len + 1, right_post_start = post_start + left_len, right_len = 0;
		right_len = in_end - in_start - left_len - 1;
		// with inorder and postorder traversal ranges, build two subtrees
		root->left = buildTreeHelper(inorder, left_in_start, left_in_start + left_len, postorder, left_post_start, left_post_start + left_len);
		root->right = buildTreeHelper(inorder, right_in_start, right_in_start + right_len, postorder, right_post_start, right_post_start + right_len);
		return root;
	}
	// This function builds the binary tree given the inorder and postorder traversal
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		return buildTreeHelper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}
};
