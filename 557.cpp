class Solution {
public:
    void reverseWord(string& s, int start, int end) {
        int l = 0, r = end - start;
        for (int i = 0; i <= r / 2; i++)
            swap(s[start + i], s[start + r - i]);
        return;
    }
    string reverseWords(string s) {
        int start = 0, end;
        while ((end = s.find(' ', start)) != string::npos) {
            reverseWord(s, start, end - 1);
            start = end + 1;
        }
        reverseWord(s, start, s.size() - 1);
        return s;
    }
};
