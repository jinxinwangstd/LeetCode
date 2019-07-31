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
	TreeNode* upsideDownBinaryTree(TreeNode* root)
	{
		TreeNode *cur = root, *prev = NULL, *next = NULL, *temp = NULL;

		while (cur)
		{
			next = cur->left;

			cur->left = temp;
			temp = cur->right;
			cur->right = prev;

			prev = cur;
			cur = next;
		}
		return prev;
	}
};
