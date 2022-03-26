class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        vector<string> res;
        for (int i = 0; i < (1 << n); i++) {
            int idx = i, num_ones = 0, cur = n - 1;
            string abbr;
            while (cur >= 0) {
                if (idx & 1) {
                    num_ones++;
                }
                else {
                    abbr = (num_ones ? to_string(num_ones) : "") + abbr;
                    num_ones = 0;
                    abbr = word[cur] + abbr;
                }
                idx >>= 1;
                cur--;
            }
            abbr = (num_ones ? to_string(num_ones) : "") + abbr;
            res.push_back(abbr);
        }
        return res;
    }
};
