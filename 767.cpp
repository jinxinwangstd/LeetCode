#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> freq(26, 0);
        for (char c : S)
            freq[c - 'a']++;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; i++)
            if (freq[i] > 0)
                pq.push(make_pair(freq[i], i));
        string ret;
        while (!pq.empty()) {
            char c1 = pq.top().second + 'a';
            int num1 = pq.top().first;
            pq.pop();
            if (pq.empty()) {
                if (num1 > 1)
                    return "";
                else {
                    ret.push_back(c1);
                    break;
                }
            }
            char c2 = pq.top().second + 'a';
            int num2 = pq.top().first;
            pq.pop();
            ret.push_back(c1);
            ret.push_back(c2);
            if (num1 > 1)
                pq.push(make_pair(num1 - 1, c1 - 'a'));
            if (num2 > 1)
                pq.push(make_pair(num2 - 1, c2 - 'a'));
        }
        return ret;
    }
};
