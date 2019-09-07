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
	int max_sum;
	int recurMaxPath(TreeNode *root)
	{
		if (!root)
			return 0;
		int left_gain = max(recurMaxPath(root->left), 0);
		int right_gain = max(recurMaxPath(root->right), 0);
		int rooted_path_sum = root->val + left_gain + right_gain;
		max_sum = max(max_sum, rooted_path_sum);
		return root->val + max(left_gain, right_gain);
	}
	int maxPathSum(TreeNode* root)
	{
		max_sum	= INT_MIN;
		recurMaxPath(root);
		return max_sum;
	}
};
