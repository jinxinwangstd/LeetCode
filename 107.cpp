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
	// This function traverses a binary tree level by level in a bottom-up way
	vector< vector<int> > levelOrderBottom(TreeNode* root)
	{
		// traverses the binary tree level by level in a top-down way
		vector<vi> reverse_ret;
		int count = 0, next_count = 0;
		queue<TreeNode *> q;
		if (root)
		{
			count++;
			q.push(root);
		}
		while (count)
		{
			vi elems;
			next_count = 0;
			// gradually visit all nodes in the current level
			while (count)
			{
				TreeNode *elem = q.front();
				q.pop();
				count--;
				elems.push_back(elem->val);
				// record the nodes in next level
				if (elem->left)
				{
					q.push(elem->left);
					next_count++;
				}
				if (elem->right)
				{
					q.push(elem->right);
					next_count++;
				}
			}
			count = next_count;
			reverse_ret.push_back(elems);
		}
		vector<vi> ret;
		// reverse the order of all levels
		while (!reverse_ret.empty())
		{
			ret.push_back(reverse_ret[reverse_ret.size() - 1]);
			reverse_ret.pop_back();
		}
		return ret;
	}
};
