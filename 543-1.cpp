/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

class Solution {
public:
    int num;
    map<TreeNode*, int> ids;
    void bfs(vector<vector<int>>& adj_list, vector<int>& dist, int start) {
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < adj_list[u].size(); i++) {
                if (dist[adj_list[u][i]] < 0) {
                    dist[adj_list[u][i]] = dist[u] + 1;
                    q.push(adj_list[u][i]);
                }
            }
        }
        return; 
    }
    void dfs(vector<vector<int>>& adj_list, TreeNode *root) {
        if (!root)
            return;
        if (root->left) {
            adj_list[ids[root]].push_back(ids[root->left]);
            adj_list[ids[root->left]].push_back(ids[root]);
            dfs(adj_list, root->left);
        }
        if (root->right) {
            adj_list[ids[root]].push_back(ids[root->right]);
            adj_list[ids[root->right]].push_back(ids[root]);
            dfs(adj_list, root->right);
        }
        return;
    }
    void assignID(TreeNode *root) {
        if (!root)
            return;
        ids[root] = num++;
        assignID(root->left);
        assignID(root->right);
        return;
    }
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root)
            return 0;
        num = 0;
        assignID(root);
        vector<vector<int>> adj_list(num, vector<int>());
        dfs(adj_list, root);
        // the first time of BFS to find one end of the diameter
        vector<int> dist(num, -1);
        bfs(adj_list, dist, 0);
        int end = max_element(dist.begin(), dist.end()) - dist.begin();
        dist.assign(num, -1);
        bfs(adj_list, dist, end);
        return *max_element(dist.begin(), dist.end());
    }
};

/*
 * BFS
 * The method to calculate the diameter of a binary tree
 */
