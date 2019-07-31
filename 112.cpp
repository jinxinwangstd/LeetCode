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
	vi elems;
	bool dfs(TreeNode *root, int depth, int sum, int target)
	{
		int temp = elems[depth];
		sum += (root->val - elems[depth]);
		elems[depth] = root->val;
		if (!root->left && !root->right)
		{
			elems[depth] = temp;
			return sum == target;
		}
		bool ret = false;
		if (root->left)
		{
			ret = dfs(root->left, depth + 1, sum, target);
			if (ret)
				return ret;
		}
		if (root->right)
		{
			ret = dfs(root->right, depth + 1, sum, target);
			if (ret)
				return ret;
		}
		elems[depth] = temp;
		return false;
	}
	bool hasPathSum(TreeNode* root, int sum)
	{
		if (!root)
			return false;
		elems.assign(1000, 0);
		return dfs(root, 0, 0, sum);
	}
};
