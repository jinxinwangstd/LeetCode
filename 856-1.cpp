class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        for (int ch : S) {
            if (ch == '(')
                s.push(ch);
            else {
                if (s.top() == '(') {
                    s.pop();
                    s.push(-1);
                }
                else {
                    int sum = 0;
                    while (s.top() != '(') {
                        sum += s.top();
                        s.pop();
                    }
                    s.pop();
                    s.push(2 * sum);
                }
            }
        }
        int res = 0;
        while (!s.empty()) {
            res += -s.top();
            s.pop();
        }
        return res;
    }
};
