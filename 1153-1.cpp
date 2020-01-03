class Solution {
public:
    bool canConvert(string str1, string str2) {
        vector<int> mapping(26, -1);
        int n = str1.size();
        for (int i = 0; i < n; i++) {
            int ch1 = str1[i] - 'a';
            int ch2 = str2[i] - 'a';
            if (mapping[ch1] >= 0 && mapping[ch1] != ch2)
                return false;
            mapping[ch1] = ch2;
        }
        return set(str2.begin(), str2.end()).size() < 26;
    }
};

/*
 * Graph
 */
