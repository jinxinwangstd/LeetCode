#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string res;
        for (int i = 0; i < n; i++) {
            while (res.size() > 0 && num[i] < res.back() && n - i + res.size() - 1 >= n - k)
                res.pop_back();
            if (res.size() < n - k)
                res.push_back(num[i]);
        }
        while (res[0] == '0')
            res.erase(res.begin());
        if (res.empty())
            res = "0";
        return res;
    }
};
