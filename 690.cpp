#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

/*
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee *> record;
        for (int i = 0; i < employees.size(); i++)
            record[employees[i]->id] = employees[i];
        queue<int> ids;
        ids.push(id);
        int res = 0;
        while (!ids.empty()) {
            int people = ids.front();
            ids.pop();
            res += record[people]->importance;
            for (int i = 0; i < record[people]->subordinates.size(); i++)
                ids.push(record[people]->subordinates[i]);
        }
        return res;
    }
};
