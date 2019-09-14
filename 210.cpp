#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // construct the graph in adjacent list form
        vector<vector<int>> adj_list(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            adj_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        // BFS
        vector<pair<int, int>> dist(numCourses, make_pair(-1, -1));
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (degree[i] == 0) {
                dist[i] = make_pair(0, i);
                q.push(i);
            }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < adj_list[node].size(); i++)
                if (dist[adj_list[node][i]].first == -1 || dist[adj_list[node][i]].first < dist[node].first + 1) {
                    dist[adj_list[node][i]] = make_pair(dist[node].first + 1, adj_list[node][i]);
                    q.push(adj_list[node][i]);
                    // handle loops in graph
                    if (dist[adj_list[node][i]].first >= numCourses)
                        return vector<int>();
                }
        }
        sort(dist.begin(), dist.end());
        vector<int> res;
        if (dist[0].first == -1)
            return res;
        for (int i = 0; i < numCourses; i++)
            res.push_back(dist[i].second);
        return res;
    }
};
