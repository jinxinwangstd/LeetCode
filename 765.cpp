#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> positions(n, -1);
        for (int i = 0; i < n; i++)
            positions[row[i]] = i;
        int count = 0;
        for (int i = 0; i < n; i += 2) {
            bool pair_flag = false;
            int pair_num;
            if (row[i] % 2)
                pair_num = row[i] - 1;
            else
                pair_num = row[i] + 1;
            if (row[i + 1] == pair_num)
                continue;
            // not paired
            int swap_num = row[i + 1];
            row[positions[pair_num]] = swap_num;
            row[i + 1] = pair_num;
            swap(positions[swap_num], positions[pair_num]);
            count++;
        }
        return count;
    }
};
