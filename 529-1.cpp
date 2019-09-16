#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(click[0], click[1]));
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (board[x][y] == 'M') {
                board[x][y] = 'X';
                break;
            }
            int count = 0;
            for (int i = 0; i < 8; i++) {
                int adj_x = x + dx[i], adj_y = y + dy[i];
                if (adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n)
                    continue;
                if (board[adj_x][adj_y] == 'M')
                    count++;
            }
            if (count == 0) {
                board[x][y] = 'B';
                for (int i = 0; i < 8; i++) {
                    int adj_x = x + dx[i], adj_y = y + dy[i];
                    if (adj_x >= 0 && adj_x < m && adj_y >= 0 && adj_y < n && board[adj_x][adj_y] == 'E') {
                        q.push(make_pair(adj_x, adj_y));
                        board[adj_x][adj_y] = 'B';  // *** avoid board[adj_x][adj_y] repeatedly added to the queue
                    }
                }
            }
            else
                board[x][y] = '0' + count;
        }
        return board;
    }
};
