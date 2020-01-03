class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        res.push_back("");
        for (char c : S) {
            int n = res.size();
            for (int i = 0; i < n; i++) {
                if (isdigit(c))
                    res[i].push_back(c);
                else {
                    string copy = res[i];
                    res[i].push_back(c);
                    if (isupper(c))
                        copy.push_back(c - 'A' + 'a');
                    else
                        copy.push_back(c - 'a' + 'A');
                    res.push_back(copy);
                }
            }
        }
        return res;
    }
};
