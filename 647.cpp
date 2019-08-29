#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class Solution {
public:
    // This function expand a palindrome string from one or two center characters
    int expandFromCenter(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count += expandFromCenter(s, i, i);
            count += expandFromCenter(s, i, i + 1);
        }
        return count;
    }
};
