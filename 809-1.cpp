class Solution {
public:
    void generateRepre(vector<pair<int, int>>& word, string& s) {
        s.push_back(' ');
        int ch = -1, num = 0;
        for (char c : s) {
            if (ch != c) {
                if (ch > 0)
                    word.push_back(make_pair(ch, num));
                ch = c;
                num = 1;
            }
            else
                num++;
        }
        s.pop_back();
        return;
    }
    bool determineStretchy(vector<pair<int, int>>& target, vector<pair<int, int>>& word) {
        if (target.size() != word.size())
            return false;
        int n = target.size();
        for (int i = 0; i < n; i++) {
            if (target[i].first != word[i].first)
                return false;
            if (target[i].second >= 3) {
                if (target[i].second < word[i].second)
                    return false;
            }
            else {
                if (target[i].second != word[i].second)
                    return false;
            }
        }
        return true;
    }
    int expressiveWords(string S, vector<string>& words) {
        vector<pair<int, int>> target;
        generateRepre(target, S);
        int res = 0;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            vector<pair<int, int>> word;
            generateRepre(word, words[i]);
            res += determineStretchy(target, word);
        }
        return res;
    }
};

/*
 * Simulation
 */
