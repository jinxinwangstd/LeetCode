class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int size = 256;
        int n = s.size();
        vector<int> mapping1(size, -1);
        vector<int> mapping2(size, -1);
        for (int i = 0; i < n; i++) {
            int ch1 = s[i];
            int ch2 = t[i];
            if (mapping1[ch1] == -1)
                mapping1[ch1] = ch2;
            if (mapping2[ch2] == -1)
                mapping2[ch2] = ch1;
            if (mapping1[ch1] != ch2)
                return false;
            if (mapping2[ch2] != ch1)
                return false;
        }
        return true;
    }
};

/*
 * One-to-One mapping
 */
