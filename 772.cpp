class Solution {
public:
    int calculateHelper(string& s, int& cur) {
        int n = s.size();
        deque<int> nums;
        deque<char> ops;
        int res = 0, num = 0;
        bool neg_sign = false;
        while (cur < n) {
            if (s[cur] == '+' || s[cur] == '-' || s[cur] == '*' || s[cur] == '/' || s[cur] == ')') {
                nums.push_back(num);
                num = 0;
                neg_sign = false;
                if (!ops.empty() && (ops.back() == '*' || ops.back() == '/')) {
                    int num2 = nums.back();
                    nums.pop_back();
                    int num1 = nums.back();
                    nums.pop_back();
                    char op = ops.back();
                    ops.pop_back();
                    if (op == '*')
                        res = num1 * num2;
                    else
                        res = num1 / num2;
                    nums.push_back(res);
                }
                if (s[cur] == ')')
                    break;
                else if (s[cur] == '-') {
                    neg_sign = true;
                    ops.push_back('+');
                }
                else
                    ops.push_back(s[cur]);
            }
            else if (isdigit(s[cur])) {
                num *= 10;
                if (neg_sign)
                    num -= s[cur] - '0';
                else
                    num += s[cur] - '0';
            }
            else if (s[cur] == '(') {
                num = calculateHelper(s, ++cur);
                if (neg_sign)
                    num = -num;
            }
            cur++;
        }
        if (cur == n)
            nums.push_back(num);
        while (!ops.empty()) {
            int num1 = nums.front();
            nums.pop_front();
            int num2 = nums.front();
            nums.pop_front();
            char op = ops.front();
            ops.pop_front();
            if (op == '+')
                res = num1 + num2;
            else
                res = num1 - num2;
            nums.push_front(res);
        }
        return nums.back();
    }
    int calculate(string s) {
        int cur = 0;
        s.insert(s.begin(), '(');
        s.push_back(')');
        return calculateHelper(s, cur);
    }
};
