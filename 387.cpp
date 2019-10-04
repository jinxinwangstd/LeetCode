class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> pos(26, INT_MAX);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (pos[c - 'a'] == INT_MAX)
                pos[c - 'a'] = i;
            else if (pos[c - 'a'] >= 0)
                pos[c - 'a'] = -1;
        }
        int res = INT_MAX;
        for (int i = 0; i < 26; i++)
            if (pos[i] >= 0)
                res = min(res, pos[i]);
        return res == INT_MAX ? -1 : res;
    }
};
