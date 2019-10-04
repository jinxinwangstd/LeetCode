class Solution {
public:
    int calculateHelper(string& s, int& cur) {
        int n = s.size();
        deque<int> nums;
        deque<char> ops;
        int num = 0;
        while (cur < n && s[cur] != ')') {
            if (s[cur] == '+' || s[cur] == '-') {
                nums.push_back(num);
                num = 0;
                ops.push_back(s[cur]);
            }
            else if (isdigit[s[cur]]) {
                num *= 10;
                num += s[cur] - '0';
            }
            else if (s[cur] == '(') {
                num = calculateHelper(s, ++cur);
            }
            cur++;
        }
        nums.push_back(num);
        while (!ops.empty()) {
            int num1 = nums.front();
            nums.pop_front();
            int num2 = nums.front();
            nums.pop_front();
            char op = ops.front();
            ops.pop_front();
            int res;
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
        return calculateHelper(s, cur);
    }
};
