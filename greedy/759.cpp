#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Interval {
public:
    int start;
    int end;

    Interval() {}
    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval *> employeeFreeTime(vector<vector<Interval *>> schedule) {
        vector<Interval *> free_time(1, new Interval(INT_MIN, INT_MAX));
        int n = schedule.size();
        for (int i = 0; i < n; i++) {
            vector<Interval *> work_time = schedule[i];
            vector<Interval *>::iterator iter1 = free_time.begin(), iter2 = work_time.begin();
            while (iter2 != work_time.end()) {
                while ((*iter2)->start >= (*iter1)->end)
                    iter1++;
                if ((*iter2)->end <= (*iter1)->start) {
                    iter2++;
                    continue;
                }
                Interval *free = *iter1, *work = *iter2;
                Interval *new_free1 = NULL, *new_free2 = NULL, *new_work = NULL;
                if (free->end > work->end)
                    new_free2 = new Interval(work->end, free->end);
                else if (work->end > free->end)
                    new_work = new Interval(free->end, work->end);
                if (free->start < work->start)
                    new_free1 = new Interval(free->start, work->start);
                iter1 = free_time.erase(iter1);
                if (new_free2)
                    iter1 = free_time.insert(iter1, new_free2);
                if (new_free1)
                    iter1 = free_time.insert(iter1, new_free1);
                if (new_work)
                    iter2 = work_time.insert(next(iter2, 1), new_work);
                else
                    iter2++;
            }
        }
        free_time.erase(free_time.begin());
        free_time.erase(prev(free_time.end(), 1));
        return free_time;
    }
};
