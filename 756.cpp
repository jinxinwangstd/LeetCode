class Solution {
public:
    unordered_map<string, vector<char>> blocks;
    bool dfs(vector<char>& stack, int pos) {
        if (stack.size() - pos == 2)
            return true;
        if (stack[pos + 1] == ' ') {
            stack.push_back(' ');
            bool res = dfs(stack, pos + 2);
            stack.pop_back();
            return res;
        }
        string base;
        base.push_back(stack[pos]);
        base.push_back(stack[pos + 1]);
        bool res = false;
        for (int i = 0; i < blocks[base].size(); i++) {
            stack.push_back(blocks[base][i]);
            res = res || dfs(stack, pos + 1);
            if (res)
                return true;
            stack.pop_back();
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (int i = 0; i < allowed.size(); i++)
            blocks[allowed[i].substr(0, 2)].push_back(allowed[i][2]);
        vector<char> stack;
        for (int i = 0; i < bottom.size(); i++)
            stack.push_back(bottom[i]);
        stack.push_back(' ');
        return dfs(stack, 0);
    }
};
