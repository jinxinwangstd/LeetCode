#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution
{
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = generatePalindrome(s, i, i);
            int len2 = generatePalindrome(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start + 1) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    // This function generate a palindrome from a single character or two characters
    int generatePalindrome(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;    // left and right is the position of two non-palindrome characters
    }
};
