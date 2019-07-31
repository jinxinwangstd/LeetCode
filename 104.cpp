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
	int depth, max_depth;
	// This function implements depth-first search with recording the depth of nodes
	void dfs(TreeNode *root)
	{
		depth++;	// entering the next level
		if (!root->left && !root->right)		// leaf nodes
		{
			max_depth = max(max_depth, depth);
			depth--;
			return;
		}
		// non-leaf nodes
		if (root->left)
			dfs(root->left);
		if (root->right)
			dfs(root->right);
		depth--;	// return to the last level
		return;
	}
	// This function determines the maximum depth of a binary tree based on depth-first search
	// The basic idea is to traverse the tree and compare the depth of all leaf nodes
	int maxDepth(TreeNode* root)
	{
		depth = 0;
		max_depth = 0;
		if (root)
			dfs(root);
		return max_depth;
	}
};
