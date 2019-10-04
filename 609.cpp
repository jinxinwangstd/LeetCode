class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<vector<int>>> groups;
        vector<int> dir_lens;
        int n = paths.size();
        for (int i = 0; i < n; i++) {
            int start, end, l, r;
            start = paths[i].find(' ') + 1;
            dir_lens.push_back(start - 1);
            while ((end = paths[i].find('(', start)) != string::npos) {
                l = end + 1;
                r = paths[i].find(')', l);
                vector<int> record;
                record.push_back(i);
                record.push_back(start);
                record.push_back(end);
                groups[paths[i].substr(l, r - l)].push_back(record);
                start = r + 2;
            }
        }
        vector<vector<string>> res;
        for (map<string, vector<vector<int>>>::iterator iter = groups.begin(); iter != groups.end(); iter++) {
            vector<string> group;
            int m = iter->second.size();
            if (m > 1) {
                for (int i = 0; i < m; i++) {
                    int dir_index = iter->second[i][0];
                    int start = iter->second[i][1];
                    int end = iter->second[i][2];
                    group.push_back(paths[dir_index].substr(0, dir_lens[dir_index]) + 
                        "\/" + paths[dir_index].substr(start, end - start));
                }
                res.push_back(group);
            }
        }
        return res;
    }
};
