#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int calculateScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int sum = 0;
        for (int i = 0; i < m; i++) {
            int score = 0;
            for (int j = 0; j < n; j++)
                score = (score << 1) + A[i][j];
            sum += score;
        }
        return sum;
    }
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int score = calculateScore(A);
        // toggle each row
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                A[i][j] = A[i][j] ? 0 : 1;
            int new_score = calculateScore(A);
            if (new_score > score)
                score = new_score;
            else {
                // toggle back
                for (int j = 0; j < n; j++)
                    A[i][j] = A[i][j] ? 0 : 1;
            }
        }
        // toggle each column
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++)
                A[i][j] = A[i][j] ? 0 : 1;
            int new_score = calculateScore(A);
            if (new_score > score)
                score = new_score;
            else {
                // toggle back
                for (int i = 0; i < m; i++)
                    A[i][j] = A[i][j] ? 0 : 1;
            }
        }
        return score;
    }
};
