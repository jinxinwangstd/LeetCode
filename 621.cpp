#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int task_nums[26];
        memset(task_nums, 0, sizeof(task_nums));
        for (vector<char>::iterator iter = tasks.begin(); iter != tasks.end(); iter++) {
            task_nums[*iter - 'A']++;
        }
        priority_queue<int> pq;
        bool last_round = true;
        for (int i = 0; i < 26; i++)
            if (task_nums[i] > 0) {
                pq.push(task_nums[i]);
                if (task_nums[i] > 1)
                    last_round = false;
            }
        int res = 0;
        while (!pq.empty()) {
            if (last_round) {
                res += pq.size();
                break;
            }
            priority_queue<int> next;
            last_round = true;
            for (int i = 0; i <= n; ++i) {
                if (pq.empty())
                    res++;
                else {
                    int num = pq.top();
                    pq.pop();
                    res++;
                    if (num - 1 > 0) {
                        next.push(num - 1);
                        if (num - 1 > 1)
                            last_round = false;
                    }
                }
            }
            while (!pq.empty()) {
                next.push(pq.top());
                if (pq.top() > 1)
                    last_round = false;
                pq.pop();
            }
            pq = next;
        }
        return res;
    }
};
