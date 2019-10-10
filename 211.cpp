// Trie
class WordDictionary {
public:
    /* Initialize your data structure here. */
    WordDictionary() {
        trie = vector<vector<int>>(2, vector<int>(26, 0));
        total = 1;
        end = vector<bool>(2, false);
    }

    /* Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.size(), p = 1;
        for (int i = 0; i < n; i++) {
            int ch = word[i] - 'a';
            if (trie[p][ch] == 0) {
                trie[p][ch] = ++total;
                trie.push_back(vector<int>(26, 0));
                end.push_back(false);
            }
            p = trie[p][ch];
        }
        end[p] = true;
    }

    /* Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, 0, 1); 
    }
    bool searchHelper(string& word, int pos, int p) {
        if (pos == word.size())
            return end[p];
        bool res = false;
        if (word[pos] == '.')
            for (int i = 0; i < 26; i++)
                if (trie[p][i] > 0) {
                    int next_p = trie[p][i];
                    res = res || searchHelper(word, pos+1, next_p);
                }
        else {
            int ch = word[pos] - 'a';
            int next_p = trie[p][ch];
            if (next_p == 0)
                return false;
            res = searchHelper(word, pos+1, next_p);
        }
        return res;
    }
private:
    vector<vector<int>> trie;
    int total;
    vector<bool> end;
};
