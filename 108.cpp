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
	TreeNode *buildBSTFromArray(vi& nums, int start, int end)
	{
		if (start == end)
			return NULL;
		// find the root value, which is the middle element in the range
		int root_index = (start + end) / 2;
		TreeNode *root = new TreeNode(nums[root_index]);
		// build two subtrees
		root->left = buildBSTFromArray(nums, start, root_index);
		root->right = buildBSTFromArray(nums, root_index + 1, end);
		return root;
	}
	// This function builds a height-balanced binary search tree from a sorted array
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		return buildBSTFromArray(nums, 0, nums.size());
	}
};
