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
    int calculateMaxPoints(vector< vector<vi> >& table, vi& boxes, int left, int right, int dups) {
        if (left > right)
            return 0;
        if (table[left][right][dups] != 0)
            return table[left][right][dups];
        // calculate the tailing repeated elements
        while (right > left && boxes[right] == boxes[right - 1]) {
            right--;
            dups++;
        }
        table[left][right][dups] = calculateMaxPoints(table, boxes, left, right, dups);
        for (int i = left; i < right; ++i) {
            if (boxes[i] == boxes[right])
                table[left][right][dups] = max(table[left][right][dups], 
                        calculateMaxPoints(table, boxes, left, i, dups + 1) + calculateMaxPoints(table, boxes, i + 1, right - 1, 0));
        }
        return table[left][right][dups];
    }
    int removeBoxes(vector<int>& boxes) {
        int n = (int)boxes.size();
        vector< vector<vi> > table(n, vector<vi>(n, vi(n, 0)));
        return calculateMaxPoints(table, boxes, 0, n - 1, 0);
    }
};
