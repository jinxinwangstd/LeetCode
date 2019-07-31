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
	// This function traverses a tree in the zigzag level order
	// The basic idea is to traverses the tree in normal level order and then reverse the even levels
	vector< vector<int> > zigzagLevelOrder(TreeNode* root)
	{
		queue<TreeNode *> q;
		int counter = 0, next_counter = 0, level = 0;
		vector<vi> ret;
		if (root)					// for the root level
		{
			q.push(root);
			counter++;
		}
		while (counter)				// if the current level has nodes, we enter the loop
		{
			level++;
			vi elems;
			next_counter = 0;
			while (counter)			// gradually pop out all nodes in current level
			{
				TreeNode *elem = q.front();
				q.pop();
				counter--;
				elems.push_back(elem->val);
				// record nodes in the next level
				if (elem->left)
				{
					q.push(elem->left);
					next_counter++;
				}
				if (elem->right)
				{
					q.push(elem->right);
					next_counter++;
				}
			}
			counter = next_counter;
			// reverse the elements in even levels
			if (!(level % 2))
			{
				int i = 0, j = elems.size() - 1;
				while (i < j)
				{
					swap(elems[i], elems[j]);
					i++;
					j--;
				}
			}
			ret.push_back(elems);
		}
		return ret;
	}
};
