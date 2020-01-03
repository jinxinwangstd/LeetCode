class Solution {
public:
    int dv[8] = {-4, -3, -2, -1, 1, 2, 3, 4};
    int dfs(set<int>& pressed, set<int>& nexts, int m, int n) {
        if (pressed.size() >= n)
            return 0;
        int res = 0, num = nexts.size();
        for (int i = 0; i < num; i++) {
            int key = *next(nexts.begin(), i);
            vector<int> added;
            nexts.erase(key);
            for (int j = 0; j < 8; j++) {
                int adj = key + dv[j];
                if (adj < 1 || adj > 9)
                    continue;
                if (pressed.count(adj))
                    continue;
                nexts.insert(adj);
                added.push_back(adj);
            }
            pressed.insert(key);
            if (pressed.size() >= m && pressed.size() <= n)
                res++;
            res += dfs(pressed, nexts, m, n);
            for (int added_key : added)
                nexts.erase(added_key);
            nexts.insert(key);
            pressed.erase(key);
        }
        return res;
    }
    int numberOfPatterns(int m, int n) {
        set<int> pressed, nexts;
        int res = m > 1 ? 0 : 9;
        for (int i = 1; i <= 9; i++) {
            pressed.clear();
            nexts.clear();
            pressed.insert(i);
            for (int j = 0; j < 8; j++) {
                int adj = i + dv[j];
                if (adj < 1 || adj > 9)
                    continue;
                nexts.insert(adj);
            }
            res += dfs(pressed, nexts, m, n);
        }
        return res;
    }
};
