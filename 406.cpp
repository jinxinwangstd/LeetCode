#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    static bool compare(vector<int>& p1, vector<int>& p2) {
        if (p1[0] > p2[0])
            return true;
        else if (p1[0] < p2[0])
            return false;
        else
            return p1[1] < p2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> q;
        int n = people.size();
        // sort people according to higher one first, and then fewer front people first
        sort(people.begin(), people.end(), compare);
        for (int i = 0; i < n; ++i)
            q.insert(q.begin() + people[i][1], people[i]);
        return q;
    }
};
