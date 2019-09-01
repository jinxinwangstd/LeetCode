#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class Solution {
public:
    vector<vi> first_table, second_table;
    int firstPlay(vi& piles, int left, int right) {
        if (left > right)
            return 0;
        if (first_table[left][right] != 0)
            return first_table[left][right];
        int score = max(piles[left] + secondPlay(piles, left + 1, right), 
                piles[right] + secondPlay(piles, left, right - 1));
        return first_table[left][right] = score;
    }
    int secondPlay(vi& piles, int left, int right) {
        if (left > right)
            return 0;
        if (second_table[left][right] != 0)
            return second_table[left][right];
        int score = max(piles[left] + firstPlay(piles, left + 1, right),
                piles[right] + firstPlay(piles, left, right - 1));
        return second_table[left][right] = score;
    }
    bool stoneGame(vector<int>& piles) {
        int n = (int)piles.size();
        first_table.assign(n, vi(n, 0));
        second_table.assign(n, vi(n, 0));
        firstPlay(piles, 0, n - 1);
        return first_table[0][n - 1] > max(second_table[1][n - 1], second_table[0][n - 2]);
    }
};
