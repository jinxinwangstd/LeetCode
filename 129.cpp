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
	int ret;
	void dfs(TreeNode *root, int num)
	{
		num *= 10;
		num += root->val;
		if (!root->left && !root->right)
		{
			ret += num;
			return;
		}
		if (root->left)
			dfs(root->left, num);
		if (root->right)
			dfs(root->right, num);
		return;
	}
	int sumNumbers(TreeNode* root)
	{
		ret = 0;
		if (!root)
			return ret;
		dfs(root, 0);
		return ret;
	}
};
