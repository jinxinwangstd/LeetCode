class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> counts(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                int ch = words[i][j] - 'a';
                counts[i] |= (1 << ch);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!(counts[i] & counts[j]))
                    res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};
