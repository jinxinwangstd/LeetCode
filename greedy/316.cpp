#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, priority_queue<int, vector<int>, greater<int>>> positions;
        map<char, int> last;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            positions[s[i]].push(i);
            last[s[i]] = i;
        }
        int m = positions.size();
        string ret(m, ' ');
        for (int i = 0; i < m; i++) {
            for (map<char, priority_queue<int, vector<int>, greater<int>>>::iterator iter = positions.begin(); iter != positions.end(); iter++) {
                int pos = iter->second.top();
                map<char, priority_queue<int, vector<int>, greater<int>>>::iterator iter2 = next(iter, 1);
                bool check_flag = true;
                while (iter2 != positions.end()) {
                    if (pos > last[iter2->first]) {
                        check_flag = false;
                        break;
                    }
                    iter2++;
                }
                if (check_flag) {
                    ret[i] = iter->first;
                    last.erase(iter->first);
                    positions.erase(iter);
                    for (iter2 = positions.begin(); iter2 != positions.end(); iter2++) {
                        while (iter2->second.top() < pos)
                            iter2->second.pop();
                    }
                    break;
                }
            }
        }
        return ret;
    }
};
