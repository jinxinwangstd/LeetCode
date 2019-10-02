// Find all nodes in a directed graph that would go into a cycle
class Solution {
public:
    const int WHITE = 0;
    const int GRAY = 1;
    const int BLACK = 2;
    void dfs(vector<bool>& flags, vector<vector<int>>& g, vector<int>& stack, vector<int>& color, int u) {
        color[u] = GRAY;
        stack.push_back(u);
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (color[v] == WHITE)  // never visted
                dfs(flags, g, stack, color, v);
            else if (color[v] == GRAY) {  // visit a parent node
                for (int j = 0; j < stack.size(); j++)
                    flags[stack[j]] = false;
            }
            else if (!flags[v]) {     // jumps into a cycle
                for (int j = 0; j < stack.size(); j++)
                    flags[stack[j]] = false;
            }
        }
        stack.pop_back();
        color[u] = BLACK;
    }    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> flags(n, true);
        vector<int> color(n, WHITE);
        vector<int> stack;
        for (int i = 0; i < n; i++)
            if (color[i] == WHITE)
                dfs(flags, graph, stack, color, i);
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (flags[i])
                res.push_back(i);
        return res;
    }
};
