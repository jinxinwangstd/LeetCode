class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int mid = floor((n - 1) / (double)2);
        for (int i = 0; i <= mid; i++)
            swap(s[i], s[n - 1 - i]);
        return;                                                                           
    }
};
