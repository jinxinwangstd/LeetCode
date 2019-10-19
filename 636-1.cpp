class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<pair<int, int>> s;
        int id = 0, time = 0;
        bool start_flag = false;
        for (int i = 0; i < logs.size(); i++) {
            int start = 0, end = 0;
            end = logs[i].find(':', start);
            id = stoi(logs[i].substr(start, end - start));
            start = end + 1;
            start_flag = logs[i][start] == 's';
            end = logs[i].find(':', start);
            start = end + 1;
            time = stoi(logs[i].substr(start));
            if (start_flag) {
                if (!s.empty())
                    res[s.top().first] += time - s.top().second;
                s.push(make_pair(id, time));
            }
            else {
                res[id] += time - s.top().second + 1;
                s.pop();
                if (!s.empty())
                    s.top().second = time + 1;
            }
        }
        return res;
    }
};
