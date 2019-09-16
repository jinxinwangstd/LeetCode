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

	vector<TreeNode *> generateSubtrees(int start, int end)
	{
		vector<TreeNode *> ret;
		if (start > end)				// base case: no value to store then it is an empty tree
		{
			ret.push_back(NULL);
			return ret;
		}
		// with the same set of values to store, a different root means a different BST
		for (int i = start; i <= end; ++i)
		{
			vector<TreeNode *> left_trees = generateSubtrees(start, i - 1);		// generate all possible left subtrees
			vector<TreeNode *> right_trees = generateSubtrees(i + 1, end);		// generate all possible right subtrees
			// link subtrees to root to form a unique tree
			for (int l = 0; l != left_trees.size(); ++l)
				for (int r = 0; r != right_trees.size(); ++r)
				{
					TreeNode *root = new TreeNode(i);
					root->left = left_trees[l];
					root->right = right_trees[r];
					ret.push_back(root);
				}
		}
		return ret;
	}
	// This function generates all structurally unique BSTs which stores values 1 to n
	vector<TreeNode*> generateTrees(int n)
	{
		vector<TreeNode *> ret;
		if (!n)
			return ret;
		ret = generateSubtrees(1, n);
		return ret;
	}
};
