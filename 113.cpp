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
	void dfs(vector<vi>& ret, TreeNode *root, vi& elems, int sum)
	{
		elems.push_back(root->val);
		if (!root->left && !root->right && accumulate(elems.begin(), elems.end(), 0) == sum)
			ret.push_back(elems);
		if (root->left)
			dfs(ret, root->left, elems, sum);
		if (root->right)
			dfs(ret, root->right, elems, sum);
		elems.pop_back();
		return;
	}
	vector< vector<int> > pathSum(TreeNode* root, int sum)
	{
		vector<vi> ret;
		if (!root)
			return ret;
		vi elems;
		dfs(ret, root, elems, sum);
		return ret;
	}
};
