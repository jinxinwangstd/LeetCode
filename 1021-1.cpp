class Solution {
public:
    string removeOuterParentheses(string S) {
        int depth = 0;
        string res;
        for (char c : S) {
            if (c == '(') {
                if (depth > 0)
                    res.push_back(c);
                depth++;
            }
            else {
                depth--;
                if (depth > 0)
                    res.push_back(c);
            }
        }
        return res;
    }
};

/*
 * Remove all parentheses whose depth is 0, which means the outer-most
 */
