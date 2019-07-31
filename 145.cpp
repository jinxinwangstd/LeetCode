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
	void postorder(TreeNode *root, vi& ret)
	{
		if (!root)
			return;
		postorder(root->left, ret);
		postorder(root->right, ret);
		ret.push_back(root->val);
		return;
	}
	vector<int> postorderTraversal(TreeNode* root)
	{
		vi ret;
		postorder(root, ret);
		return ret;
	}
};
