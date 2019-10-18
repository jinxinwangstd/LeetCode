class Solution {
public:
    bool compareString(string& a, string& b, int a_i, int b_i) {
        int m = a.size(), n = b.size();
        int i = a_i, j = b_i;
        while (i < m && j < n) {
            if (a[i] != b[j])
                return false;
            i++;
            j++;
        }
        return true;
    }
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int m = indexes.size(), n = S.size();
        vector<int> record(n, -1);
        for (int i = 0; i < m; i++) {
            if (compareString(S, sources[i], indexes[i], 0)) {
                record[indexes[i]] = i;
                for (int j = 1; j < sources[i].size(); j++)
                    record[indexes[i] + j] = INT_MIN;
            }
        }
        string res;
        for (int i = 0; i < n; i++) {
            if (record[i] > -1)
                res.append(targets[record[i]]);
            else if (record[i] == -1)
                res.push_back(S[i]);
        }
        return res;
    }
};
