class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for (char c : s) {
            int ch = c - 'a';
            res ^= ch;
        }
        for (char c : t) {
            int ch = c - 'a';
            res ^= ch;
        }
        return (char)(res + 'a');
    }
};
