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
	vector<int> rightSideView(TreeNode* root)
	{
		vi ret;
		if (!root)
			return ret;
		// Breadth-first search
		int num = 1, next_num = 0;
		queue<TreeNode*> nodes;
		nodes.push(root);
		while (!nodes.empty())
		{
			next_num = 0;
			for (int i = 0; i < num; ++i)
			{
				TreeNode *node = nodes.front();
				nodes.pop();
				if (node->left)
				{
					nodes.push(node->left);
					next_num++;
				}
				if (node->right)
				{
					nodes.push(node->right);
					next_num++;
				}
				if (i == num - 1)
				{
					ret.push_back(node->val);
				}
			}
			num = next_num;
		}
		return ret;
	}
};
