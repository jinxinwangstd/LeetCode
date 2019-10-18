class Solution {
public:
    bool isValid(string s) {
        // Use stack to pair couple of valid parentheses
        stack<char> remains;
        for (int i = 0; i < s.size(); i++) {
            // no remaining parentheses
            if (remains.empty())    
                remains.push(s[i]);
            // next parentheses is left parentheses so we cannot pair it with the last one
            else if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                remains.push(s[i]);
            // next parentheses is right parentheses
            else {
                char last = remains.top();
                // only valid pair can be removed
                if ((s[i] == ')' && last == '(') ||
                    (s[i] == '}' && last == '{') ||
                    (s[i] == ']' && last == '['))
                    remains.pop();
                else
                    return false;
            }
        }
        // Empty means all pairs are valid so they are all removed
        return remains.empty();
    }
};
