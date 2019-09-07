#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int n_multiplier = 3;
const int multipliers[] = {2, 3, 5};

class Solution {
public:
    int nthUglyNumber(int n) {
        set<int> s;
        priority_queue<int, greater<int> > q;
        s.insert(1);
        q.push(1);
        int id = 0, ans = 0;
        while (!q.empty()) {
            ans = q.top();
            ++id;
            q.pop();
            if (id == n)
                break;
            for (int i = 0; i != n_multiplier; ++i) {
                int next = ans * multipliers[i];
                if (!s.count(next)) {
                    s.insert(next);
                    q.push(next);
                }
            }
        }
        return ans;
    }
};

