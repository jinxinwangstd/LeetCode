class Solution {
public:
    static bool compare(const string& s1, const string& s2) {
        int space1 = s1.find(' ');
        int space2 = s2.find(' ');
        string body1 = s1.substr(space1);
        string body2 = s2.substr(space2);
        if (body1 != body2)
            return body1 < body2;
        else
            return s1 < s2;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        int n = logs.size();
        for (int i = 0; i < n; i++)
            if (isalpha(logs[i].back()))
                res.push_back(logs[i]);
        sort(res.begin(), res.end(), compare);
        for (int i = 0; i < n; i++)
            if (isdigit(logs[i].back()))
                res.push_back(logs[i]);
        return res;
    }
};
