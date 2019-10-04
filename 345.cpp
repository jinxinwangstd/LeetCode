class Solution {
public:
    string reverseVowels(string s) {
        const string vowels = "aeiouAEIOU";
        int n = s.size();
        vector<int> vowels_pos;
        for (int i = 0; i < n; i++)
            if (vowels.find(s[i]) != string::npos)
                vowels_pos.push_back(i);
        n = vowels_pos.size();
        int mid = (int)floor((n - 1) / (double)2);
        for (int i = 0; i <= mid; i++) {
            int l = vowels_pos[i], r = vowels_pos[n - 1 - i];
            swap(s[l], s[r]);
        }
        return s;
    }
};
