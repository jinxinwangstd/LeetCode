class Solution {
public:
    char ops[4] = {'+', '-', '*', '/'};
    int calculate(deque<char>& equation, int pos) {
         
    }
    bool validEquation(vector<char>& equation) {
        int n = equation.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (equation[i] == '(')
                count++;
            else if (equation[i] == ')')
                count--;
            if (count < 0)
                return false;
        }
        return count == 0;
    }
    bool dfs(vector<int>& nums, vector<char>& equation, int pos) {
        if (pos == 7) {
            if (validEquation(equation)) {
                int res = calculate(equation, 0);
                return res == 24;
            }
        }
        if (pos % 2) {
            for (int i = 0; i < 4; i++) {
                equation.push_back(ops[i]);
                if (dfs(nums, equation, pos + 1))
                    return true;
                equation.pop_back();
            }
        }
        else {
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                bool res = false;
                equation.push_back('(');
                equation.push_back('0' + nums[i]);
                res = res || dfs(nums, equation, pos + 1);
                equation.pop_back();
                equation.pop_back();
                equation.push_back('0' + nums[i]);
                res = res || dfs(nums, equation, pos + 1);
                equation.push_back(')');
                res = res || dfs(nums, equation, pos + 1);
                equation.pop_back();
                equation.pop_back();
                if (res)
                    return res;
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& nums) {
    
    }
};
