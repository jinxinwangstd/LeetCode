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
	// This function puts values at a same level into one array, and all arrays into one big arrays, basically traversing a tree in level order
	// The basic idea is to use BFS with a queue
	vector< vector<int> > levelOrder(TreeNode* root)
	{
		queue<TreeNode *> q;
		int counter = 0, next_counter = 0;		// counter records the number of nodes in current level, and next_counter records the number of nodes in next level
		vector<vi> ret;
		if (root)				// for the root level
		{
			q.push(root);
			counter++;
		}
		while (counter)			// if current level have nodes, we enter the loop
		{
			vi level;
			next_counter = 0;
			while (counter)		// gradually pop out nodes in the current level
			{
				TreeNode *elem = q.front();
				q.pop();
				counter--;
				level.push_back(elem->val);
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
			ret.push_back(level);
		}
		return ret;
	}
};
