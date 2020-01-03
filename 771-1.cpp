class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<int> letters(52, 0);
        for (char c : S) {
            if (islower(c))
                letters[c - 'a' + 26]++;
            else
                letters[c - 'A']++;
        }
        int res = 0;
        for (char c : J) {
            if (islower(c))
                res += letters[c - 'a' + 26];
            else
                res += letters[c - 'A'];
        }
        return res;
    }
};

/*
 * Letter frequency storing in arrays
 */
