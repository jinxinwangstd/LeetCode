#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    void bfs(vector<vector<int>>& board, vector<int>& dist, int start) {
        int N = board.size();
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        while (!q.empty()) {
            int id = q.front();
            q.pop();
            for (int i = 1; i <= 6; i++) {
                int adj_id = id + i;
                if (adj_id < N * N) {
                    bool jump_flag = false;
                    if (dist[adj_id] == -1 || dist[adj_id] > dist[id] + 1) {
                        dist[adj_id] = dist[id] + 1;
                        jump_flag = true;
                    }
                    int x = N - 1 - adj_id / N;
                    int y = (adj_id / N) % 2 ? N - 1 - adj_id % N : adj_id % N;
                    if (board[x][y] != -1) {
                        if (dist[board[x][y] - 1] == -1 || dist[board[x][y] - 1] > dist[id] + 1) {
                            dist[board[x][y] - 1] = dist[id] + 1;
                            q.push(board[x][y] - 1);
                        }
                    }
                    else if (jump_flag)
                        q.push(adj_id);
                }
            }
        }
        return;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        vector<int> dist(N * N, -1);
        bfs(board, dist, 0);
        return dist[N * N - 1];
    }
};
