class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size() != words2.size())
            return false;
        int n = words1.size(), m = pairs.size();
        map<string, set<string>> pairing;
        for (int i = 0; i <m; i ++) {
            pairing[pairs[i][0]].insert(pairs[i][1]);
            pairing[pairs[i][1]].insert(pairs[i][0]);
        }
        for (int i = 0; i < n; i++) {
            if (words1[i] != words2[i] && !pairing[words1[i]].count(words2[i]))
                return false;
        }
        return true;
    }
};

/*
 * Hash table
 */
