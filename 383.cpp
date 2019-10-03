class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ransom_counts(26, 0);
        vector<int> mag_counts(26, 0);
        for (char c : ransomNote)
            ransom_counts[c - 'a']++;
        for (char c : magazine)
            mag_counts[c - 'a']++;
        for (int i = 0; i < 26; i++)
            if (ransom_counts[i] > mag_counts[i])
                return false;
        return true;
    }
};
