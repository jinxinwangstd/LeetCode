class Trie {
public:
    /* Initialize your data structure here. */
    Trie() {
        trie = vector<vector<int>>(1, vector<int>(26, -1));
        total = 0;
        end = vector<bool>(1, false);
    }

    /* Insert a word into the trie. */
    void insert(string word) {
        int n = word.size(), p = 0;
        for (int i = 0; i < n; i++) {
            int ch = word[i] - 'a';
            if (trie[p][ch] == -1) {
                trie[p][ch] = ++total;
                trie.push_back(vector<int>(26, -1));
                end.push_back(false);
            }
            p = trie[p][ch];
        }
        end[p] = true;
    }

    /* Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size(), p = 0;
        for (int i = 0; i < n; i++) {
            int ch = word[i] - 'a';
            p = trie[p][ch];
            if (p == -1)
                return false;
        }
        return end[p];
    }

    /* Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size(), p = 0;
        for (int i = 0; i < n; i++) {
            int ch = prefix[i] - 'a';
            p = trie[p][ch];
            if (p == -1)
                return false;
        }
        bool res = end[p];
        for (int i = 0; i < 26; i++)
            res = res || (trie[p][i] > -1);
        return res;
    }
private:
    vector<vector<int>> trie;
    int total;
    vector<bool> end;
};
