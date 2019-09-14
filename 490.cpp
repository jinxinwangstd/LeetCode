#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> reachable(m, vector<bool>(n, false));
        reachable[start[0]][start[1]] = true;
        q.push(make_pair(start[0], start[1]));
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            int dest_x = x, dest_y = y;
            // to the right
            while (dest_y + 1 < n && maze[dest_x][dest_y + 1] == 0)
                dest_y++;
            if (!reachable[dest_x][dest_y]) {
                reachable[dest_x][dest_y] = true;
                q.push(make_pair(dest_x, dest_y));
            }
            // to the left
            dest_x = x, dest_y = y;
            while (dest_y - 1 >= 0 && maze[dest_x][dest_y - 1] == 0)
                dest_y--;
            if (!reachable[dest_x][dest_y]) {
                reachable[dest_x][dest_y] = true;
                q.push(make_pair(dest_x, dest_y));
            }
            // to the upper
            dest_x = x, dest_y = y;
            while (dest_x - 1 >= 0 && maze[dest_x - 1][dest_y] == 0)
                dest_x--;
            if (!reachable[dest_x][dest_y]) {
                reachable[dest_x][dest_y] = true;
                q.push(make_pair(dest_x, dest_y));
            }
            // to the lower
            dest_x = x, dest_y = y;
            while (dest_x + 1 < m && maze[dest_x + 1][dest_y] == 0)
                dest_x++;
            if (!reachable[dest_x][dest_y]) {
                reachable[dest_x][dest_y] = true;
                q.push(make_pair(dest_x, dest_y));
            }
        }
        return reachable[destination[0]][destination[1]];
    }
};
