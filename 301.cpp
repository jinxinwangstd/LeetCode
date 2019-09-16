#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    bool validateParentheses(string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(')
                count++;
            if (c == ')')
                count--;
            if (count < 0)
                return false;
        }
        return count == 0;
    }
    void dfs(set<string>& res, string& s, string& t, int pos) {
        if (pos == s.size()) {
            if (!validateParentheses(t))
                return;
            if (res.empty()) {
                res.insert(t);
                return;
            }
            set<string>::iterator iter = res.begin();
            if (t.size() > (*iter).size()) {
                res.clear();
                res.insert(t);
            }
            else if (t.size() == (*iter).size())
                res.insert(t);
            return;
        }
        if (s[pos] != '(' && s[pos] != ')') {
            t.push_back(s[pos]);
            dfs(res, s, t, pos + 1);
            t.pop_back();
            return;
        }
        dfs(res, s, t, pos + 1);
        t.push_back(s[pos]);
        dfs(res, s, t, pos + 1);
        t.pop_back();
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> record;
        string t;
        dfs(record, s, t, 0);
        vector<string> res;
        for (set<string>::iterator iter = record.begin(); iter != record.end(); iter++)
            res.push_back(*iter);
        return res;
    }
};
