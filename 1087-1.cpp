class Solution {
public:
    void dfs(vector<string>& res, string& state, string& S, int pos) {
        if (pos == S.size()) {
            res.push_back(state);
            return;
        }
        if (S[pos] == '{') {
            vector<char> chs;
            while (S[pos] != '}') {
                if (isalpha(S[pos]))
                    chs.push_back(S[pos]);
                pos++;
            }
            // lexicographical order
            sort(chs.begin(), chs.end());
            for (char c : chs) {
                state.push_back(c);
                dfs(res, state, S, pos + 1);
                state.pop_back();
            }
        }
        else {
            state.push_back(S[pos]);
            dfs(res, state, S, pos + 1);
            state.pop_back();
        }
        return;
    }
    vector<string> expand(string S) {
        vector<string> res;
        string state;
        dfs(res, state, S, 0);
        return res;
    }
};

/*
 * DFS
 */
