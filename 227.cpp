class Solution {
public:
    int calculate(string s) {
        s.push_back('+');   // add a '+' for easily implementation
        deque<int> nums;
        deque<char> ops;
        int n = s.size();
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                nums.push_back(num);
                num = 0;
                if (!ops.empty() && (ops.back() == '*' || ops.back() == '/')) {
                    int num2 = nums.back();
                    nums.pop_back();
                    int num1 = nums.back();
                    nums.pop_back();
                    char op = ops.back();
                    ops.pop_back();
                    int res;
                    if (op == '*')
                        res = num1 * num2;
                    else
                        res = num1 / num2;
                    nums.push_back(res);
                }
                ops.push_back(s[i]);
            }
            else if (isdigit(s[i])) {
                num *= 10;
                num += s[i] - '0';
            }
        }
        ops.pop_back();   // clear the '+' we add
        while (!ops.empty()) {
            int num1 = nums.front();
            nums.pop_front();
            int num2 = nums.front();
            nums.pop_front();
            char op = ops.front();
            ops.pop_front();
            int res;
            switch(op) {
                case '+':
                    res = num1 + num2;
                    break;
                case '-':
                    res = num1 - num2;
                    break;
            }
            nums.push_front(res);
        }
        return nums.back();
    }
};
