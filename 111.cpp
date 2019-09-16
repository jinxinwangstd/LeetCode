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
	int min_height;
	void dfs(TreeNode *root, int height)
	{
		height++;
		if (!root->left && !root->right)
		{
			min_height = min(height, min_height);
			return;
		}
		if (root->left)
			dfs(root->left, height);
		if (root->right)
			dfs(root->right, height);
		return;
	}
	int minDepth(TreeNode* root)
	{
		if (!root)
			return 0;
		min_height = INT_MAX;
		dfs(root, 0);
		return min_height;
	}
};
