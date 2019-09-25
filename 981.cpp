class TimeMap {
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        vector<pair<int, string>> record = m[key];
        int n = record.size();
        int l = 0, r = n - 1, mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            if (record[mid].first > timestamp)
                r = mid;
            else
                l = mid;
        }
        if (record[r].first <= timestamp)
            return record[r].second;
        else if (record[l].first <= timestamp)
            return record[l].second;
        else
            return "";
    }
private:
    unordered_map<string, vector<pair<int, string>>> m;
};
