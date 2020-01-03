class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string typed_S, typed_T;
        for (char c : S) {
            if (c == '#') {
                if (!typed_S.empty())
                    typed_S.pop_back();
            }
            else
                typed_S.push_back(c);
        }
        for (char c : T) {
            if (c == '#') {
                if (!typed_T.empty())
                    typed_T.pop_back();
            }
            else
                typed_T.push_back(c);
        }
        return typed_S == typed_T;
    }
};

/*
 * Stack
 */
