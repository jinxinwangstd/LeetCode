#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // with pre_sum[prefix_sum along this root path, num of prefix sum], we can calculate node range sum along this root path
    int pathSumHelper(TreeNode *root, int cur_sum, int sum, unordered_map<int, int>& pre_sum) {
        if (!root)
            return 0;
        cur_sum += root->val;   // prefix sum from root to this node
        int ret = pre_sum.count(cur_sum - sum) ? pre_sum[cur_sum - sum] : 0;
        pre_sum[cur_sum]++;     // add this prefix sum into the prefix sum collection along this root path

        ret += pathSumHelper(root->left, cur_sum, sum, pre_sum) + pathSumHelper(root->right, cur_sum, sum, pre_sum);
        pre_sum[cur_sum]--;     // delete this prefix sum to restore prefix sum collection
        return ret;
    }
    int pathSum(TreeNode *root, int sum) {
        unordered_map<int, int> pre_sum;
        pre_sum[0] = 1;
        return pathSumHelper(root, 0, sum, pre_sum);
    }
};
