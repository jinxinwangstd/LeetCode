#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        vector<int> dist(numCourses, INT_MAX);
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            adj_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (degree[i] == 0) {
                q.push(i);
                dist[i] = 0;
            }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < adj_list[node].size(); i++) {
                int adj_node = adj_list[node][i];
                degree[adj_node]--;
                if (degree[adj_node] == 0) {
                    q.push(adj_node);
                    if (dist[adj_node] == INT_MAX)
                        dist[adj_node] = dist[node] + 1;
                    else
                        return false;
                }
            }
        }
        for (int i = 0; i < numCourses; i++)
            if (dist[i] == INT_MAX)
                return false;
        return true;
    }
};
