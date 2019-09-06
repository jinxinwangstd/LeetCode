#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    static bool compare(vector<int>& p, vector<int>& q) {
        return p[1] < q[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compare);
        int n = courses.size();
        priority_queue<int> pq;
        int time = 0;
        for (int i = 0; i < n; i++) {
            if (time + courses[i][0] <= courses[i][1]) {
                time += courses[i][0];
                pq.push(courses[i][0]);
            }
            else if (!pq.empty()) {
                int max_time = pq.top();
                if (max_time > courses[i][0]) {
                    pq.pop();
                    time = time - max_time + courses[i][0];
                    pq.push(courses[i][0]);
                }
            }
        }
        return pq.size();
    }
};
